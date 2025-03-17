class Solution {
    int shortestPath(vector<int> adj[], int src, int n) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (dist[it] > dist[node] + 1) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist[n - 1];
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> adj[n];
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i+1);
        }
        for (auto query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            int newShortPath = shortestPath(adj, 0, n);
            ans.push_back(newShortPath);
        }
        return ans;
    }
};