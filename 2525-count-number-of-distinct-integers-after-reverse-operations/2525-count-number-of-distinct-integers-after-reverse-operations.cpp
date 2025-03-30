class Solution {
    int reverse(int num) {
        int rev = 0;
        while (num) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }
        return rev;
    }

public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            st.insert(reverse(nums[i]));
        }
        return st.size();
    }
};