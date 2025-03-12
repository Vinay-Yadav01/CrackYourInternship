class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            while (nums[i] <= nums[i - 1]) {
                nums[i]++;
                operations++;
            }
        }
        return operations;
    }
};