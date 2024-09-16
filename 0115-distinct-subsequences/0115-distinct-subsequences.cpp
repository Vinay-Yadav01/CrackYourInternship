class Solution {
    // int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    //     if (j < 0) // critical Step , first check this base case and then other
    //         return 1; // t is exhausted
    //     if (i < 0)
    //         return 0; // s is exhausted
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s[i] == t[j]) {
    //         return dp[i][j] = solve(i - 1, j - 1, s, t,dp) + solve(i - 1, j, s, t,dp);
    //     }
    //     return dp[i][j] = solve(i - 1, j, s, t,dp);
    // }

    //1-based Indexing
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == 0) // critical Step , first check this base case and then other
            return 1; // t is exhausted
        if (i == 0)
            return 0; // s is exhausted
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i-1] == t[j-1]) {
            return dp[i][j] = solve(i - 1, j - 1, s, t,dp) + solve(i - 1, j, s, t,dp);
        }
        return dp[i][j] = solve(i - 1, j, s, t,dp);
    }

public:
    int numDistinct(string s, string t) {
        // int n = s.size();
        // int m = t.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, s, t, dp);

        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n,m, s, t, dp);
    }
};