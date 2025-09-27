class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flipCount = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] == 1 && flipCount % 2 == 1) ||
                (nums[i] == 0 && flipCount % 2 == 0))
                flipCount++;
        }
        return flipCount;
    }
};