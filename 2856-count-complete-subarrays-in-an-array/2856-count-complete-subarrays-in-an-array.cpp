class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        int count = 0;
        int distinctNumbers = st.size();
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> temp;
            for (int j = i; j < n; j++) {
                temp.insert(nums[j]);
                if (temp.size() == distinctNumbers)
                    count++;
            }
        }
        return count;
    }
};