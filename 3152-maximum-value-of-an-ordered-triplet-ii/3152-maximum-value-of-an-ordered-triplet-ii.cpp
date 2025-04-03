class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> prefixMax(n), suffixMax(n);
        prefixMax[0] = nums[0];
        suffixMax[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(nums[i], suffixMax[i + 1]);
        }
        for (int ind = 1; ind < n - 1; ind++) {
            long long val =
                1LL * (prefixMax[ind - 1] - nums[ind]) * suffixMax[ind + 1];
            ans = max(val, ans);
        }
        return ans;
    }
};