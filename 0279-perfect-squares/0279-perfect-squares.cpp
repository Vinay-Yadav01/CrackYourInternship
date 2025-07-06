class Solution {
    int solve(int n, vector<int>& dp) {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            if (i * i > n)
                break;
            ans = min(ans, 1 + solve(n - (i * i), dp));
        }
        return dp[n] = ans;
    }

public:
    int numSquares(int n) {
        // vector<int> dp(n + 1, -1);
        // return solve(n, dp);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};