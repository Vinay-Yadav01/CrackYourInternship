class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;

        if (target < 0) return -1; // cannot remove more than total sum

        int maxLen = -1, currSum = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            currSum += nums[right];
            while (currSum > target && left <= right) {
                currSum -= nums[left++];
            }
            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return (maxLen == -1) ? -1 : n - maxLen;
    }
};
