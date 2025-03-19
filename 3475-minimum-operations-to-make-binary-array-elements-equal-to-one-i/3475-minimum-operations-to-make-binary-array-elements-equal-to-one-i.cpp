class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int flips = 0;
        while (i < n) {
            if (nums[i] == 0) {
                if (i + 2 < n) {
                    flips++;
                    nums[i] = !nums[i];
                    nums[i + 1] = !nums[i + 1];
                    nums[i + 2] = !nums[i + 2];
                } else
                    return -1;
            }
            i++;
        }
        return flips;
    }
};