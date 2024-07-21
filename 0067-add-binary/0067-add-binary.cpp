class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry) {
            int first = 0;
            int second = 0;
            if (i >= 0)
                first = a[i] - '0';
            if (j >= 0)
                second = b[j] - '0';
            int sum = first + second + carry;
            int s = sum % 2;
            carry = sum / 2;
            i--;
            j--;
            ans += to_string(s);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};