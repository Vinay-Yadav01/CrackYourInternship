class Solution {
    // int solve(int ind, int prev_ind, vector<int>& nums) {
    //     if (ind == nums.size())
    //         return 0;
    //     int len = 0 + solve(ind + 1, prev_ind, nums, dp); // Not Take
    //     if (prev_ind == -1 || nums[prev_ind] < nums[ind])
    //         len = max(len, 1 + solve(ind + 1, ind, nums, dp)); // Take
    //     return len;
    // }

    // int solve(int ind, int prev_ind, vector<int>& nums,
    //           vector<vector<int>>& dp) {
    //     if (ind == nums.size())
    //         return 0;
    //     if (dp[ind][prev_ind+1] != -1)
    //         return dp[ind][prev_ind+1];
    //     int len = 0 + solve(ind + 1, prev_ind, nums, dp); // Not Take
    //     if (prev_ind == -1 || nums[prev_ind] < nums[ind])
    //         len = max(len, 1 + solve(ind + 1, ind, nums, dp)); // Take
    //     return dp[ind][prev_ind+1] = len;
    // }

public:
    int lengthOfLIS(vector<int>& nums) {
        // return solve(0, -1, nums, dp);

        // Co-ordinate Change for prev_ind for memoization
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(0, -1, nums, dp);

        // int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
        //         int len = 0 + dp[ind + 1][prev_ind + 1]; // Not Take
        //         if (prev_ind == -1 || nums[prev_ind] < nums[ind])
        //             len = max(len, 1 + dp[ind + 1][ind + 1]); // Take
        //         dp[ind][prev_ind + 1] = len;
        //     }
        // }
        // return dp[0][0];

        int n = nums.size();
        vector<int> curr(n + 1, 0), next(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = 0 + next[prev_ind + 1]; // Not Take
                if (prev_ind == -1 || nums[prev_ind] < nums[ind])
                    len = max(len, 1 + next[ind + 1]); // Take
                curr[prev_ind + 1] = len;
            }
            next = curr;
        }
        return curr[0];
    }
};