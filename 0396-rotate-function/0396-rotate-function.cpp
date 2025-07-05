class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long totalSum = accumulate(nums.begin(), nums.end(), 0L);
        long F = 0;
        for (int i = 0; i < n; i++) {
            F += (long)i * nums[i];
        }

        long result = F;
        for (int k = 1; k < n; k++) {
            F = F + totalSum - (long)n * nums[n - k];
            result = max(result, F);
        }

        return result;
    }
};
