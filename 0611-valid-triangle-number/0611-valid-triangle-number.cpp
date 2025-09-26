class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    count += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }
        return count;
    }
};