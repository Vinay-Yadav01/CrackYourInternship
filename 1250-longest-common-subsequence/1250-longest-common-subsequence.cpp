class Solution {
    // int solve(int i, int j, string text1, string text2,vector<vector<int>>
    // &dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j]) return dp[i][j] =
    //     1+solve(i-1,j-1,text1,text2,dp); return dp[i][j] =
    //     max(solve(i-1,j,text1,text2,dp),solve(i,j-1,text1,text2,dp));
    // }

    // Shifting Of Index
    int solve(int i, int j, string text1, string text2,
              vector<vector<int>>& dp) {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i - 1] == text2[j - 1])
            return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
        return dp[i][j] = max(solve(i - 1, j, text1, text2, dp),
                              solve(i, j - 1, text1, text2, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // return solve(n-1,m-1,text1,text2,dp);

        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return solve(n,m,text1,text2,dp);

        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (text1[i - 1] == text2[j - 1])
        //             dp[i][j] = 1 + dp[i - 1][j - 1];
        //         else
        //             dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        //     }
        // }
        // return dp[n][m];

        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        return prev[m];
    }
};