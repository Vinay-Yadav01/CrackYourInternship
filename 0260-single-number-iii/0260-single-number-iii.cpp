class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long XOR = 0;
        for (int i = 0; i < n; i++) {
            XOR ^= nums[i];
        }
        int rightMost = (XOR & (XOR - 1)) ^ XOR;
        int b1 = 0, b2 = 0;
        for (int i = 0; i < n; i++) {
            int set = nums[i] & rightMost;
            if (set)
                b1 ^= nums[i];
            else
                b2 ^= nums[i];
        }
        return {b1, b2};
    }
};