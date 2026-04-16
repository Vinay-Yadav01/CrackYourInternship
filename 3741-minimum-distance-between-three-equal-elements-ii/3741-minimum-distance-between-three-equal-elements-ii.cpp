class Solution {
    int calc(vector<int>& vec) {
        int res = INT_MAX, m = vec.size();
        for (int i = 0; i + 2 < m; i++)
            res = min(res, 2 * (vec[i + 2] - vec[i]));
        return res;
    }

public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for (auto [it, vec] : mp)
            if (vec.size() >= 3)
                ans = min(ans, calc(vec));

        return ans != INT_MAX ? ans : -1;
    }
};