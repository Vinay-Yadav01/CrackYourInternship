class Solution {
    // int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    //     if (j < 0) // critical Step , first check this base case and then
    //     other
    //         return 1; // t is exhausted
    //     if (i < 0)
    //         return 0; // s is exhausted
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s[i] == t[j]) {
    //         return dp[i][j] = solve(i - 1, j - 1, s, t,dp) + solve(i - 1, j,
    //         s, t,dp);
    //     }
    //     return dp[i][j] = solve(i - 1, j, s, t,dp);
    // }

    // 1-based Indexing
    //  int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    //      if (j == 0) // critical Step , first check this base case and then
    //      other
    //          return 1; // t is exhausted
    //      if (i == 0)
    //          return 0; // s is exhausted
    //      if (dp[i][j] != -1)
    //          return dp[i][j];
    //      if (s[i-1] == t[j-1]) {
    //          return dp[i][j] = solve(i - 1, j - 1, s, t,dp) + solve(i - 1, j,
    //          s, t,dp);
    //      }
    //      return dp[i][j] = solve(i - 1, j, s, t,dp);
    //  }

public:
    int numDistinct(string s, string t) {
        // int n = s.size();
        // int m = t.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, s, t, dp);

        // int n = s.size();
        // int m = t.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(n,m, s, t, dp);

        // int n = s.size();
        // int m = t.size();
        // vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        // for (int i = 0; i <= n; i++)
        //     dp[i][0] = 1;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s[i - 1] == t[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        //         } else
        //             dp[i][j] = dp[i - 1][j];
        //     }
        // }
        // return (int)dp[n][m];

        // int n = s.size();
        // int m = t.size();
        // vector<double> prev(m + 1, 0), curr(m + 1, 0);
        // prev[0] = curr[0] = 1;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s[i - 1] == t[j - 1]) {
        //             curr[j] = prev[j - 1] + prev[j];
        //         } else
        //             curr[j] = prev[j];
        //     }
        //     prev = curr;
        // }
        // return (int)prev[m];

        int n = s.size();
        int m = t.size();
        vector<double> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >=1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j];
                } else
                    dp[j] = dp[j];
            }
        }
        return (int)dp[m];
    }
};