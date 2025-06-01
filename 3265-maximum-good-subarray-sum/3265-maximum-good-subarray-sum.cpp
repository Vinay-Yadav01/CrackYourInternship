class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> prefixSumMap; // maps num -> min prefix sum before it
        long long sum = 0;
        long long ans = LLONG_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            // Check for nums[i] - k and nums[i] + k in the map
            if (prefixSumMap.count(nums[i] - k)) {
                ans = max(ans, sum - prefixSumMap[nums[i] - k]);
            }
            if (prefixSumMap.count(nums[i] + k)) {
                ans = max(ans, sum - prefixSumMap[nums[i] + k]);
            }
            // Update prefix map: we want the earliest/smallest prefix sum for future use
            if (!prefixSumMap.count(nums[i])) {
                prefixSumMap[nums[i]] = sum - nums[i];
            } else {
                prefixSumMap[nums[i]] = min(prefixSumMap[nums[i]], sum - nums[i]);
            }
        }
        return (ans == LLONG_MIN) ? 0 : ans;
    }
};
