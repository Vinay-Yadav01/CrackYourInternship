class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        for (int ind = nums.size() - 2; ind >= 0; ind--)
            if (nums[ind] >= nums[ind + 1])
                return ind + 1;
        return 0;
    }
};