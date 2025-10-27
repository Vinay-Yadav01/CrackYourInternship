class Solution {
    int solve(vector<vector<int>>& dp, string& s, int i, int j) {
        if (i >= j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = s[i] == s[j] ? solve(dp, s, i+1, j-1) : 0;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                count += solve(dp, s, i, j);
            }
        }
        return count;
    }
};