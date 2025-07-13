class Solution {
    int MOD = 1e9 + 7;
    // int solve(int n, int ab, int clc, vector<vector<vector<int>>>& dp) {
    //     if (n == 0)
    //         return 1;
    //     if (dp[n][ab][clc] != -1)
    //         return dp[n][ab][clc];

    //     int ans = 0;
    //     ans = solve(n - 1, ab, 0, dp);
    //     if (ab < 1)
    //         ans = (ans + solve(n - 1, ab + 1, 0, dp)) % MOD;
    //     if (clc < 2)
    //         ans = (ans + solve(n - 1, ab, clc + 1, dp)) % MOD;
    //     return dp[n][ab][clc] = ans % MOD;
    // }

public:
    int checkRecord(int n) {
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(n, 0, 0, dp);

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                dp[0][j][k] = 1;
            }
        }
        for (int day = 1; day <= n; day++) {
            for (int ab = 0; ab < 2; ab++) {
                for (int clc = 0; clc < 3; clc++) {
                    int ans = 0;
                    ans = dp[day - 1][ab][0];
                    if (ab < 1)
                        ans = (ans + dp[day - 1][ab + 1][0]) % MOD;
                    if (clc < 2)
                        ans = (ans + dp[day - 1][ab][clc + 1]) % MOD;
                    dp[day][ab][clc] = ans % MOD;
                }
            }
        }
        return dp[n][0][0];
    }
};