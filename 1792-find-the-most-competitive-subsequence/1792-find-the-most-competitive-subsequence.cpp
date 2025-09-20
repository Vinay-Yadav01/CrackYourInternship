class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if (k <= 0)
            return {0};
        if (k >= nums.size()) {
            return nums;
        }
        int n = nums.size(), to_remove = n - k;
        stack<int> st;
        for (auto dig : nums) {
            while (!st.empty() && to_remove > 0 && dig < st.top()) {
                to_remove--;
                st.pop();
            }
            st.push(dig);
        }
        while (!st.empty() && to_remove > 0) {
            st.pop();
            to_remove--;
        }

        vector<int> ans(st.size());
        int idx = ans.size() - 1;
        while (!st.empty()) {
            ans[idx--] = st.top();
            st.pop();
        }
        return ans;
    }
};