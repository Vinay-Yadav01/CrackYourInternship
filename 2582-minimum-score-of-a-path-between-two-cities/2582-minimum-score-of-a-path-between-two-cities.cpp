class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto road : roads) {
            int u = road[0], v = road[1], dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
        vector<int> dist(n + 1, INT_MAX);
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nbr : adj[node]) {
                int nbrCity = nbr.first, distance = nbr.second;
                if (dist[nbrCity] == INT_MAX ||
                    min(dist[node], distance) < dist[nbrCity]) {
                    dist[nbrCity] = min(dist[node], distance);
                    q.push(nbrCity);
                }
            }
        }
        return dist[n];
    }
};