class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minPair = nums[0] + nums.back();
        int i = 0, j = nums.size() - 1;
        while (i < j) 
            minPair = max(minPair, nums[j--] + nums[i++]);
        return minPair;
    }
};