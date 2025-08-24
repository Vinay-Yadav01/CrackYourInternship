class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int flag = 1, maxLength = 0, windowLength = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (flag) {
                    flag = 0;
                    prev = i;
                } else {
                    maxLength = max(maxLength, windowLength);
                    windowLength = i - prev;
                    prev = i;
                    continue;
                }
            }
            windowLength++;
        }
        maxLength = max(maxLength, windowLength);
        return maxLength - 1;
    }
};