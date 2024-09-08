class Solution {
    string numToBinary(int num) {
        string binary = "";
        while (num > 0) {
            int bit = num & 1;
            binary = to_string(bit) + binary;
            num = num >> 1;
        }
        return binary.empty() ? "0" : binary; // Return "0" if the input is 0
    }

public:
    string convertDateToBinary(string date) {
        string temp = "";
        string ans = "";
        for (int i = 0; i < date.size(); i++) {
            if (date[i] != '-')
                temp += date[i];
            else {
                string t2 =  numToBinary(stoi(temp));
                ans += t2;
                ans += '-';
                temp = "";
            }
        }
        string t2 =  numToBinary(stoi(temp));
        ans += t2;
        return ans;
    }
};