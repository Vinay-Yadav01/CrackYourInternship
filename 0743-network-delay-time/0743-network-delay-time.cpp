class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (auto time : times) {
            int src = time[0], target = time[1], timeTaken = time[2];
            adj[src].push_back({target, timeTaken});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (dist[adjNode] > wt + edgeWeight) {
                    dist[adjNode] = wt + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            else
                ans = max(ans, dist[i]);
        }
        return ans;
    }
};