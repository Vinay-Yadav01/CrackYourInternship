class Solution {
    int f(int ind, vector<int>& nums, vector<int>& subset) {
        int n = nums.size();
        if (ind == n) {
            int XOR = 0;
            for (int num : subset) {
                XOR ^= num;
            }
            return XOR;
        }
        subset.push_back(nums[ind]);
        int take = f(ind + 1, nums, subset);
        subset.pop_back();
        int notTake = f(ind + 1, nums, subset);
        return take + notTake;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        vector<int> subset;
        return f(0, nums, subset);
    }
};