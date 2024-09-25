class Solution {
    // int solve(int ind, int buy, int cap, vector<int>& prices,
    //           vector<vector<vector<int>>>& dp) {
    //     if (ind == prices.size())
    //         return 0;
    //     if (cap == 0)
    //         return 0;
    //     if (dp[ind][buy][cap] != -1)
    //         return dp[ind][buy][cap];
    //     if (buy) {
    //         return dp[ind][buy][cap] =
    //                    max(-prices[ind] + solve(ind + 1, 0, cap, prices, dp),
    //                        0 + solve(ind + 1, 1, cap, prices, dp));
    //     } else {
    //         return dp[ind][buy][cap] =
    //                    max(prices[ind] + solve(ind + 1, 1, cap - 1, prices,
    //                    dp),
    //                        0 + solve(ind + 1, 0, cap, prices, dp));
    //     }
    // }

public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0, 1, 2, prices, dp);

        // int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         for (int cap = 1; cap <= 2; cap++) {
        //             if (buy) {
        //                 dp[ind][buy][cap] =
        //                     max(-prices[ind] + dp[ind + 1][0][cap],
        //                         0 + dp[ind + 1][1][cap]);
        //             } else {
        //                 dp[ind][buy][cap] =
        //                     max(prices[ind] + dp[ind + 1][1][cap - 1],
        //                         0 + dp[ind + 1][0][cap]);
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][2];

        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        curr[buy][cap] =
                            max(-prices[ind] + next[0][cap], 0 + next[1][cap]);
                    } else {
                        curr[buy][cap] = max(prices[ind] + next[1][cap - 1],
                                             0 + next[0][cap]);
                    }
                }
            }
            next = curr;
        }
        return curr[1][2];
    }
};