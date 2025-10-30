class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for (auto &r : roads) {
            int u = r[0], v = r[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = connected[v][u] = true;
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j] - (connected[i][j] ? 1 : 0);
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
