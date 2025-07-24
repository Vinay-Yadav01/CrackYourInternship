class Solution {
public:
    int res = INT_MAX;
    int total;
    vector<int> val;

    int dfs2(int x, int par, int ans1, int anc, vector<vector<int>>& adj,
             vector<int>& nums) {
        int xorr = val[x];
        for (auto& ch : adj[x]) {
            if (ch == par)
                continue;
            xorr ^= dfs2(ch, x, ans1, anc, adj, nums);
        }
        if (par == anc)
            return xorr;

        int third = total ^ ans1 ^ xorr;
        res = min(res, max({ans1, xorr, third}) - min({ans1, xorr, third}));
        return xorr;
    }

    int dfs(int x, int par, vector<vector<int>>& adj, vector<int>& nums) {
        int xorr = val[x];
        for (auto& ch : adj[x]) {
            if (ch == par)
                continue;
            xorr ^= dfs(ch, x, adj, nums);
        }

        for (auto& ch : adj[x]) {
            if (ch == par) {
                dfs2(ch, x, xorr, x, adj, nums);
            }
        }

        return xorr;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        total = 0;
        for (auto x : nums)
            total ^= x;

        val = nums;
        dfs(0, -1, adj, nums);
        return res;
    }
};
