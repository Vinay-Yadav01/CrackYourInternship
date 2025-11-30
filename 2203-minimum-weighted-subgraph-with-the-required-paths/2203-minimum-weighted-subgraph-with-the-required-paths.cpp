class Solution {
    const long long INF = 1e18;
    vector<long long> dijkstra(int start, vector<vector<pair<int, int>>>& adj) {
        int n = adj.size();
        vector<long long> dist(n, INF);
        dist[start] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int currentNode = pq.top().second;
            long long currentCost = pq.top().first;
            pq.pop();
            if (currentCost > dist[currentNode])
                continue;

            for (auto& edge : adj[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                long long newRouteCost = edgeLength + dist[currentNode];

                if (dist[neighbor] > newRouteCost) {
                    dist[neighbor] = newRouteCost;
                    pq.push({newRouteCost, neighbor});
                }
            }
        }
        return dist;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n), revAdj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            revAdj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<long long> dist1 = dijkstra(src1, adj);
        vector<long long> dist2 = dijkstra(src2, adj);
        vector<long long> dist3 = dijkstra(dest, revAdj);

        long long res = INF;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != INF && dist2[i] != INF && dist3[i] != INF) {
                res = min(res, dist1[i] + dist2[i] + dist3[i]);
            }
        }
        return res == INF ? -1 : res;
    }
};