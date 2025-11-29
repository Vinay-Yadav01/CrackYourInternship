class Solution {
    void dfs(int src, int curVal, int curTime, int maxTime, int& ans,
             vector<int>& values, vector<vector<pair<int, int>>>& adj) {
        if (curTime > maxTime)
            return;
        curVal += values[src];
        if (src == 0)
            ans = max(ans, curVal);
        int temp = values[src];
        values[src] = 0;
        for (auto [adjNode, time] : adj[src]) {
            dfs(adjNode, curVal, curTime + time, maxTime, ans, values, adj);
        }
        values[src] = temp;
    }

public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges,
                           int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int ans = 0;
        dfs(0, 0, 0, maxTime, ans, values, adj);
        return ans;
    }
};