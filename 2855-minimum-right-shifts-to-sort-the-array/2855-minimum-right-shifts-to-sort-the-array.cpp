class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int min = -1, count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                min = i;
                count++;
            }
        }

        if (min == -1)
            return 0;
        if (count > 1 || nums[0] < nums[n - 1])
            return -1;
        return n - min;
    }
};