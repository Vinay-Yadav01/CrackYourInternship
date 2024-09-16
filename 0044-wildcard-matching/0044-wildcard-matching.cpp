class Solution {
    // bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
    //     if (i < 0 && j < 0)
    //         return true;
    //     if (j < 0)
    //         return false;
    //     if (i < 0) {
    //         for (int ind = 0; ind <= j; ind++) {
    //             if (p[ind] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s[i] == p[j] || p[j] == '?')
    //         return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
    //     else if (p[j] == '*')
    //         return dp[i][j] =
    //                    solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
    //     else
    //         return dp[i][j] = false;
    // }

    // 1-based Indexing

    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return true;
        if (j == 0)
            return false;
        if (i == 0) {
            for (int ind = 1; ind <= j; ind++) {
                if (p[ind - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        else if (p[j - 1] == '*')
            return dp[i][j] =
                       solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
        else
            return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, p, dp);
    }
};