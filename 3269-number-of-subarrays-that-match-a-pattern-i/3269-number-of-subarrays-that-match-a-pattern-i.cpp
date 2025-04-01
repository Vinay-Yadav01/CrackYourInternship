class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;

        // Loop through the nums array to find matching subarrays
        for (int i = 0; i <= n - m - 1; i++) {
            bool match = true;

            // Check if the subarray starting at index i matches the pattern
            for (int k = 0; k < m; k++) {
                if ((pattern[k] == 1 && nums[i + k] >= nums[i + k + 1]) ||
                    (pattern[k] == 0 && nums[i + k] != nums[i + k + 1]) ||
                    (pattern[k] == -1 && nums[i + k] <= nums[i + k + 1])) {
                    match = false;
                    break;
                }
            }

            // If the subarray matches the pattern, increment the count
            if (match) {
                count++;
            }
        }

        return count;
    }
};
