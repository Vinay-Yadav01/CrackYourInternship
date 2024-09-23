class Solution {
    int solve(int ind, string& s, unordered_map<string, bool>& mp,
              vector<int>& dp) {
        if (ind >= s.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int n = s.size();
        int minExtra = n;
        string temp = "";
        for (int i = ind; i < n; i++) {
            temp += s[i];
            int currExtra = (mp.find(temp) == mp.end()) ? temp.length() : 0;
            int nextExtra = solve(i + 1, s, mp, dp);
            minExtra = min(minExtra, currExtra + nextExtra);
        }
        return minExtra;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // unordered_map<string, bool> mp;
        // int n = s.size();
        // vector<int> dp(n + 1, -1);
        // for (auto word : dictionary) {
        //     mp[word] = true;
        // }
        // return solve(0, s, mp, dp);

        unordered_map<string, bool> mp;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (auto word : dictionary) {
            mp[word] = true;
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            int minExtra = n;
            string temp = "";
            for (int i = ind; i < n; i++) {
                temp += s[i];
                int currExtra = (mp.find(temp) == mp.end()) ? temp.length() : 0;
                int nextExtra = dp[i + 1];
                minExtra = min(minExtra, currExtra + nextExtra);
            }
            dp[ind] = minExtra;
        }
        return dp[0];
    }
};