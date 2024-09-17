class Solution {
    // int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp)
    // {
    //     if (ind == prices.size())
    //         return 0;
    //     if (dp[ind][buy] != -1)
    //         return dp[ind][buy];
    //     if (buy) {
    //         return dp[ind][buy] =
    //                    max(0 + solve(ind + 1, 1, prices, dp),
    //                        -prices[ind] + solve(ind + 1, 0, prices, dp));
    //     } else {
    //         return dp[ind][buy] =
    //                    max(0 + solve(ind + 1, 0, prices, dp),
    //                        prices[ind] + solve(ind + 1, 1, prices, dp));
    //     }
    // }

public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, prices, dp);

        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // dp[n][0] = dp[n][1] = 0;
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy < 2; buy++) {
        //         if (buy) {
        //             dp[ind][buy] =
        //                 max(0 + dp[ind + 1][1], -prices[ind] + dp[ind + 1][0]);
        //         } else {
        //             dp[ind][buy] =
        //                 max(0 + dp[ind + 1][0], prices[ind] + dp[ind + 1][1]);
        //         }
        //     }
        // }
        // return dp[0][1];

        int n = prices.size();
        vector<int> curr(2, 0), next(2,0);
        next[0] = next[1] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    curr[buy] =
                        max(0 + next[1], -prices[ind] + next[0]);
                } else {
                    curr[buy] =
                        max(0 + next[0], prices[ind] + next[1]);
                }
            }
            next=curr;
        }
        return next[1];
    }
};