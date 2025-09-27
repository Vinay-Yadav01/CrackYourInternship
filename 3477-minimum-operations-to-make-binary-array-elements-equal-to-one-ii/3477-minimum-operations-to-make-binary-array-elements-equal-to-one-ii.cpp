class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flipCount = 0;
        for (int i = 0; i < n; i++) {
            int curBit = nums[i];
            int flip = flipCount % 2;
            curBit = (curBit + flip) % 2;
            if (curBit == 0) {
                flipCount++;
            }
        }
        return flipCount;
    }
};