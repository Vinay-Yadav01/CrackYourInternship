class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = INT_MAX;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = i; j < n; j++) {
                mask |= nums[j];
                if (mask >= k) {
                    minLength = min(minLength, j - i + 1);
                    break;
                }
            }
        }
        return (minLength == INT_MAX) ? -1 : minLength;
    }
};