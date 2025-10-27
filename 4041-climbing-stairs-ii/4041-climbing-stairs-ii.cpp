class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            if (j - 1 >= 0) dp[j] = min(dp[j], dp[j - 1] + costs[j - 1] + 1);
            if (j - 2 >= 0) dp[j] = min(dp[j], dp[j - 2] + costs[j - 1] + 4);
            if (j - 3 >= 0) dp[j] = min(dp[j], dp[j - 3] + costs[j - 1] + 9);
        }

        return dp[n];
    }
};