class Solution {
    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
            vector<int>& pathVis, vector<vector<int>>& count, string& colors) {
        if (pathVis[node] == 1)
            return INT_MAX;
        if (vis[node] == 1)
            return 0;
        vis[node] = 1;
        pathVis[node] = 1;
        int colorIndex = colors[node] - 'a';
        count[node][colorIndex] = 1;
        for (auto nbr : adj[node]) {
            if (dfs(nbr, adj, vis, pathVis, count, colors) == INT_MAX)
                return INT_MAX;
            for (int color = 0; color < 26; color++) {
                int nbrCount =
                    count[nbr][color] + ((color == colorIndex) ? 1 : 0);
                count[node][color] = max(count[node][color], nbrCount);
            }
        }
        pathVis[node] = 0;
        return *max_element(count[node].begin(), count[node].end());
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        int res = 0;
        vector<vector<int>> count(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, adj, vis, pathVis, count, colors));
        }
        return (res == INT_MAX) ? -1 : res;
    }
};