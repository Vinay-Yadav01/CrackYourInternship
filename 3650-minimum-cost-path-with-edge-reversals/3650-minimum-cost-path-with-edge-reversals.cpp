class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> dist(n, INT_MAX);
        dist[0] = 1;
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (node == n - 1)
                return d;
            for (auto it : adj[node]) {
                int nbr = it.first, wt = it.second;
                if (dist[nbr] > d + wt) {
                    dist[nbr] = d + wt;
                    pq.push({d + wt, nbr});
                }
            }
        }
        return -1;
    }
};