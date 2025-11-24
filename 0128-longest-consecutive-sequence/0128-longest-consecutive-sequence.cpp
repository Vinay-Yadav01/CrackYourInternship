class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = 0;

        for (int x : st) {
            if (st.count(x - 1)) continue;

            int cnt = 1, curr = x;
            while (st.count(curr + 1)) {
                curr++;
                cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
