class Solution {
    double solve(int ind, int k, int n, vector<int>& nums,
                 vector<vector<double>>& dp) {
        if (ind == n)
            return 0;
        if (k == 1) {
            double count = 0;
            int total = n - ind;
            for (int i = ind; i < n; i++)
                count += nums[i];
            return count / total;
        }
        if (dp[ind][k] != -1)
            return dp[ind][k];
        double count = 0, total = 0;
        double ans = INT_MIN;
        for (int i = ind; i < n; i++) {
            count += nums[i];
            total++;
            ans = max(ans, count / total + solve(i + 1, k - 1, n, nums, dp));
        }
        return dp[ind][k] = ans;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k + 1, -1));
        return solve(0, k, n, nums, dp);
    }
};