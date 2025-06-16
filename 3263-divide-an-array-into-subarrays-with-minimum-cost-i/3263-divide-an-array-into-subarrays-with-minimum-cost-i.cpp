class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size(), mini = INT_MAX, i = 0;
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                mini = min(mini, nums[i] + nums[j] + nums[k]);
            }
        }
        return mini;
    }
};