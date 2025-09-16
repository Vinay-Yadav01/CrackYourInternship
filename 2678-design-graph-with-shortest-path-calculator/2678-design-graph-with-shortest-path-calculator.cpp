class Graph {
    vector<vector<pair<int, int>>> adj;

    int dijkstra(int start, int end) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int currentNode = pq.top().second;
            int currentCost = pq.top().first;
            pq.pop();

            if(currentNode == end)
                return currentCost ;

            for (auto edge : adj[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + dist[currentNode];

                if (dist[neighbor] > newRouteCost) {
                    dist[neighbor] = newRouteCost;
                    pq.push({newRouteCost, neighbor});
                }
            }
        }
        return ((dist[end] == INT_MAX) ? -1 : dist[end]);
    }

public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
    }

    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */