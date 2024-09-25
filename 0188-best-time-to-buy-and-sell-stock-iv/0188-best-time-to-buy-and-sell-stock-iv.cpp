class Solution {
    // int solve(int ind, int trans, int k, vector<int>& prices,
    //           vector<vector<int>>& dp) {
    //     if (ind == prices.size())
    //         return 0;
    //     if (trans == 2*k)
    //         return 0;
    //     if (dp[ind][trans] != -1)
    //         return dp[ind][trans];
    //     if (trans % 2 == 0) {
    //         return dp[ind][trans] = max(
    //                    -prices[ind] + solve(ind + 1, trans + 1, k, prices,
    //                    dp), 0 + solve(ind + 1, trans, k, prices, dp));
    //     } else {
    //         return dp[ind][trans] = max(
    //                    prices[ind] + solve(ind + 1, trans + 1, k, prices,
    //                    dp), 0 + solve(ind + 1, trans, k, prices, dp));
    //     }
    // }

public:
    int maxProfit(int k, vector<int>& prices) {
        // Similar as Previous Question, only change it k transactions
        // Therefore for all solution refer those
        // int n = prices.size();
        // vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        // vector<vector<int>> next(2, vector<int>(k + 1, 0));
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         for (int cap = 1; cap <= k; cap++) {
        //             if (buy) {
        //                 curr[buy][cap] =
        //                     max(-prices[ind] + next[0][cap], 0 +
        //                     next[1][cap]);
        //             } else {
        //                 curr[buy][cap] = max(prices[ind] + next[1][cap - 1],
        //                                      0 + next[0][cap]);
        //             }
        //         }
        //     }
        //     next = curr;
        // }
        // return curr[1][k];

        // Another Approach in which we can reduce Space Complexity and that
        // also applies on Prvious Question too

        // int n = prices.size();
        // vector<vector<int>> dp(
        //     n + 1, vector<int>(2*k+1,-1));
        // return solve(0, 0, k, prices, dp);

        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int trans = 0; trans < 2 * k; trans++) {
        //         if (trans % 2 == 0) {
        //             dp[ind][trans] = max(-prices[ind] + dp[ind + 1][trans + 1],
        //                                  0 + dp[ind + 1][trans]);
        //         } else {
        //             dp[ind][trans] = max(prices[ind] + dp[ind + 1][trans + 1],
        //                                  0 + dp[ind + 1][trans]);
        //         }
        //     }
        // }
        // return dp[0][0];

        int n = prices.size();
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 0; trans < 2 * k; trans++) {
                if (trans % 2 == 0) {
                    curr[trans] = max(-prices[ind] + next[trans + 1],
                                         0 + next[trans]);
                } else {
                    curr[trans] = max(prices[ind] + next[trans + 1],
                                         0 + next[trans]);
                }
            }
            next = curr;
        }
        return curr[0];
    }
};