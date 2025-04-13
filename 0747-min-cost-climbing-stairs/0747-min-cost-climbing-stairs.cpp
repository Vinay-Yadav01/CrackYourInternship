class Solution {
    int f(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind == 0 || ind == 1) return 0;
        if (dp[ind] != -1) return dp[ind];

        int oneStep = cost[ind - 1] + f(ind - 1, cost, dp);
        int twoStep = cost[ind - 2] + f(ind - 2, cost, dp);
        return dp[ind] = min(oneStep, twoStep);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return f(n, cost, dp);
    }
};
