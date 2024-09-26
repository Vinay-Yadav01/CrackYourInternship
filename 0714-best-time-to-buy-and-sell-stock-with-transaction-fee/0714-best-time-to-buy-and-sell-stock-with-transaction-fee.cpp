class Solution {
    int solve(int ind, int buy, vector<int>& prices, int fee,
              vector<vector<int>>& dp) {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy) {
            return dp[ind][buy] =
                       max(0 + solve(ind + 1, 1, prices, fee, dp),
                           -prices[ind] + solve(ind + 1, 0, prices, fee, dp));
        } else {
            return dp[ind][buy] = max(
                       0 + solve(ind + 1, 0, prices, fee, dp),
                       prices[ind] + solve(ind + 1, 1, prices, fee, dp) - fee);
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};