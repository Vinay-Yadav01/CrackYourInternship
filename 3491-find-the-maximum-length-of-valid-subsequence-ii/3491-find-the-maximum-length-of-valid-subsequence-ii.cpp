class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++) {
            int currRem = nums[i] % k;
            for (int j = 0; j < k; j++) {
                dp[currRem][j] = max(dp[currRem][j], 1 + dp[j][currRem]);
                ans = max(ans, dp[currRem][j]);
            }
        }
        return ans;
    }
};