class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else if (nums[mid] < nums[e]) {
                e = mid;
            } else {
                e--;  // only difference: skip duplicate
            }
        }
        return nums[s];
    }
};
