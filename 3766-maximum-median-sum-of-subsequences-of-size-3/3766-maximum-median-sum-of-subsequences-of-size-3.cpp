class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return nums.back();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int i = 0, j = n - 2;
        while (i < j) {
            ans += nums[j];
            j -= 2;
            i++;
        }
        return ans;
    }
};