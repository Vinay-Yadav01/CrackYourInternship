class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minVal(n);
        minVal[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            minVal[i] = min(minVal[i + 1], nums[i]);

        int maxVal = -1;
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
            if (maxVal - minVal[i] <= k)
                return i;
        }
        return -1;
    }
};