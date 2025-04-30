class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int digit = (log10(num) + 1);
            if (digit % 2 == 0)
                count++;
        }
        return count;
    }
};