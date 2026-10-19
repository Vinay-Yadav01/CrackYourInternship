class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> degree;

        for (const auto& adj : adjacentPairs) {
            int u = adj[0], v = adj[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        int startNode = -1;
        for (auto& pair : degree) {
            if (pair.second == 1) {
                startNode = pair.first;
                break;
            }
        }

        vector<int> res;
        int curr = startNode;
        int prev = 1e9;
        while (true) {
            res.push_back(curr);
            const auto& neighbors = graph[curr];
            int nextNode = -1;
            for (int neighbor : neighbors) {
                if (neighbor != prev) {
                    nextNode = neighbor;
                    break;
                }
            }

            if (nextNode == -1)
                break;

            prev = curr;
            curr = nextNode;
        }

        return res;
    }
};