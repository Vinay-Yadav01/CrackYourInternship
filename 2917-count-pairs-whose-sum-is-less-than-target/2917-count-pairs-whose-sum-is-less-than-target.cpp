class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            int ind = lower_bound(nums.begin() + i + 1, nums.end(), rem) -
                      nums.begin();
            count += (ind - (i + 1));
        }
        return count;
    }
};
