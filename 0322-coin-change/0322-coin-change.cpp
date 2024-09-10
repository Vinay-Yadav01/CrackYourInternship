class Solution {
    // int solve(vector<int>& coins, int ind, int target,
    //           vector<vector<int>>& dp) {
    //     if (ind == 0) {
    //         if (target % coins[0] == 0)
    //             return target / coins[0];
    //         else
    //             return 1e9;
    //     }
    //     if (dp[ind][target] != -1)
    //         return dp[ind][target];
    //     int notTake = solve(coins, ind - 1, target, dp);
    //     int take = INT_MAX;
    //     if (coins[ind] <= target)
    //         take = 1 + solve(coins, ind, target - coins[ind], dp);
    //     return dp[ind][target] = min(notTake, take);
    // }

public:
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // int ans = solve(coins, n - 1, amount, dp);
        // if (ans == 1e9)
        //     return -1;
        // return ans;

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = 1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notTake = dp[ind - 1][target];
                int take = INT_MAX;
                if (coins[ind] <= target)
                    take = 1 + dp[ind][target - coins[ind]];
                dp[ind][target] = min(notTake, take);
            }
        }
        int ans = dp[n - 1][amount];
        if (ans == 1e9)
            return -1;
        return ans;
    }
};