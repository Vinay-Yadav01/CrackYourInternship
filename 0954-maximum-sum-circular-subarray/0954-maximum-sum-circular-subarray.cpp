class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int totalSum = 0;

        int currMaxSUM = 0;
        int currMinSUM = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];

            currMaxSUM += nums[i];
            maxSum = max(maxSum, currMaxSUM);
            currMaxSUM = currMaxSUM < 0 ? 0 : currMaxSUM;

            currMinSUM += nums[i];
            minSum = min(minSum, currMinSUM);
            currMinSUM = currMinSUM > 0 ? 0 : currMinSUM;
        }
        if (totalSum == minSum)
            return maxSum;
        return max(maxSum, (totalSum - minSum));
    }
};