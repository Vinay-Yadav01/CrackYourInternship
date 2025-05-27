class Solution {
    void solve(int ind, string& digits, string& temp, vector<string>& ans,
               vector<string>& numToChar) {
        int n = digits.size();
        if (ind >= n) {
            ans.push_back(temp);
            return;
        }
        string keys = numToChar[digits[ind] - '0'];
        for (int i = 0; i < keys.size(); i++) {
            temp.push_back(keys[i]);
            solve(ind + 1, digits, temp, ans, numToChar);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> numToChar = {"",    "",    "abc",  "def", "ghi",
                                    "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string temp = "";
        solve(0, digits, temp, ans, numToChar);
        return ans;
    }
};