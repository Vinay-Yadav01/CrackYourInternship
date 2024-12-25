class Solution {
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis,
             vector<int>& tin, vector<int>& low,
             vector<vector<int>>& critical) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            else if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, critical);
                low[node] = min(low[node], low[it]);

                // Check for bridge
                if (low[it] > tin[node])
                    critical.push_back({node, it});
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0), tin(n, 0), low(n, 0);
        vector<vector<int>> critical;
        dfs(0, -1, adj, vis, tin, low, critical);
        return critical;
    }
};