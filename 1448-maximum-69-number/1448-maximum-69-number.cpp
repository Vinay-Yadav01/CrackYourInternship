class Solution {
public:
    int maximum69Number(int num) {
        int maxi = num;
        string numString = to_string(num);
        for (int i = 0; i < numString.size(); i++) {
            if (numString[i] == '6') {
                numString[i] = '9';
                maxi = max(maxi, stoi(numString));
                numString[i] = '6';
            } else {
                numString[i] = '6';
                maxi = max(maxi, stoi(numString));
                numString[i] = '9';
            }
        }
        return maxi;
    }
};