class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            int suffixSum = sum - nums[i] - prefixSum;
            if (prefixSum == suffixSum)
                return i;
            prefixSum += nums[i];
        }
        return -1;
    }
};