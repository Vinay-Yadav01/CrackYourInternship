class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Iterate over each bit position
        for (int i = 0; i < 32; i++) {
            int count1 = 0;
            for (int num : nums) {
                count1 += (num >> i) & 1; // Check if the i-th bit is set
            }
            int count0 = n - count1;
            ans += count1 * count0; // Contribution of the i-th bit to the Hamming distance
        }

        return ans;
    }
};
