class Solution {
    int n;
    int solve(int ind, int freeInd, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (ind >= n)
            return 0;
        if (dp[ind][freeInd] != -1)
            return dp[ind][freeInd];
        int op1 = prices[ind] + solve(ind + 1, ind + 1, prices, dp);
        int op2 = 1e9;
        for (int i = 1; i <= freeInd; i++)
            op2 = min(op2, solve(ind + i, 0, prices, dp));
        return dp[ind][freeInd] = min(op1, op2);
    }

public:
    int minimumCoins(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, prices, dp);
    }
};