class Solution {
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = -1e8;
        for (int ind = i; ind <= j; ind++) {
            int coin = nums[i - 1] * nums[ind] * nums[j + 1] +
                       solve(i, ind - 1, nums, dp) +
                       solve(ind + 1, j, nums, dp);
            maxi = max(maxi, coin);
        }
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        // nums.push_back(1);
        // nums.insert(nums.begin(), 1);
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(1, n - 2, nums, dp);

        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 2; i >= 1; i--) {
            for (int j = i; j <= n - 2; j++) {
                int maxi = -1e8;
                for (int ind = i; ind <= j; ind++) {
                    int coin = nums[i - 1] * nums[ind] * nums[j + 1] +
                               dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, coin);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 2];
    }
};