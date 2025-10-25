class Solution {
    void solve(string& s, unordered_set<string>& st, int ind, int n,
               string& temp, vector<string>& ans) {
        if (ind == n) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string str = "";
        for (int i = ind; i < n; i++) {
            str += s[i];
            if (st.find(str) != st.end()) {
                string cur = temp;
                temp += str + " ";
                solve(s, st, i + 1, n, temp, ans);
                temp = cur;
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string> ans;
        string temp = "";
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        solve(s, st, 0, n, temp, ans);
        return ans;
    }
};