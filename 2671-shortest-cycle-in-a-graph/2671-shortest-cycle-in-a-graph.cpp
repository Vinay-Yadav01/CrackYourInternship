class Solution {
    void bfs(int node, int n, vector<vector<int>>& adj, int &ans) {
        vector<int> vis(n, 0), dist(n, 0);
        queue<pair<int,int>> q;
        q.push({node, -1});
        vis[node] = 1;

        while(!q.empty()) {
            auto [curr, parent] = q.front();
            q.pop();

            for(int nbr : adj[curr]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    dist[nbr] = dist[curr] + 1;
                    q.push({nbr, curr});
                } 
                else if(nbr != parent) {
                    ans = min(ans, dist[curr] + dist[nbr] + 1);
                }
            }
        }
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            bfs(i, n, adj, ans);
            if(ans == 3) return 3; // shortest possible cycle
        }
        return ans == INT_MAX ? -1 : ans;
    }
};