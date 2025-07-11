class Solution {
    void dfs(int node, vector<int> adj[], set<pair<int, int>>& edges,
             vector<int>& vis, int& count) {
        vis[node] = 1;
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                if (edges.count({nbr,node}) == 0)
                    count++;
                dfs(nbr, adj, edges, vis, count);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        set<pair<int, int>> edges;
        for (auto connection : connections) {
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
            edges.insert({u, v});
        }
        vector<int> vis(n, 0);
        int count = 0;
        dfs(0, adj, edges, vis, count);
        return count;
    }
};