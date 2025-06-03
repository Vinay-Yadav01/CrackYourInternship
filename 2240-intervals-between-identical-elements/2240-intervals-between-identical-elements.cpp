class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
            mp[arr[i]].push_back(i);

        vector<long long> ans(n, 0);
        for (auto& [val, indices] : mp) {
            int m = indices.size();
            vector<long long> prefix(m, 0);
            prefix[0] = indices[0];

            // Build prefix sum of indices
            for (int i = 1; i < m; ++i)
                prefix[i] = prefix[i - 1] + indices[i];

            for (int i = 0; i < m; ++i) {
                int idx = indices[i];
                long long left = (long long)i * idx - (i > 0 ? prefix[i - 1] : 0);
                long long right = (prefix[m - 1] - prefix[i]) - (long long)(m - 1 - i) * idx;
                ans[idx] = left + right;
            }
        }
        return ans;
    }
};
