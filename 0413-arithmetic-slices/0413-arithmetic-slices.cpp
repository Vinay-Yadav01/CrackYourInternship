class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;
        int i = 0, n = nums.size();
        if( n < 3 ) return 0;
        while (i < n - 1) {
            int j = i + 1;
            int diff = nums[j] - nums[i];
            while (j < n && (nums[j] - nums[j - 1] == diff)) {
                j++;
            }
            if (j - i >= 3)
                total += (j - i - 2) * (j - i - 1) / 2;
            i = j-1;
        }
        return total;
    }
};