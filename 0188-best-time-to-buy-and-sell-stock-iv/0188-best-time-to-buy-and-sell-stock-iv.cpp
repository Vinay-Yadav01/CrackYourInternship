class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // Similar as Previous Question, only change it k transactions
        // Therefore for all solution refer those
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
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
        return curr[1][k];
    }
};