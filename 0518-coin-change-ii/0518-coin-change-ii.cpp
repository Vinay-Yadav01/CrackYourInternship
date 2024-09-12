class Solution {
private:
    int solve(vector<int>& coins, int ind, int target,
              vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target % coins[0] == 0)
                return 1;
            else
                return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = solve(coins, ind - 1, target, dp);
        int take = 0;
        if (coins[ind] <= target)
            take = solve(coins, ind, target - coins[ind], dp);
        return dp[ind][target] = (notTake + take);
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(coins, n - 1, amount, dp);
        ;
    }
};