class Solution {
    int MOD = 1e9 + 7;
    int solve(int n, int ab, int clc, vector<vector<vector<int>>>& dp) {
        if (n == 0)
            return 1;
        if (dp[n][ab][clc] != -1)
            return dp[n][ab][clc];

        int ans = 0;
        ans = solve(n - 1, ab, 0, dp);
        if (ab < 1)
            ans = (ans + solve(n - 1, ab + 1, 0, dp)) % MOD;
        if (clc < 2)
            ans = (ans + solve(n - 1, ab, clc + 1, dp)) % MOD;
        return dp[n][ab][clc] = ans % MOD;
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, dp);
    }
};