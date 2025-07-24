class Solution {
    void shortest_distance(vector<vector<long long>>& matrix, int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] =
                        min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        const int ALPHA = 26;

        vector<vector<long long>> adj(ALPHA, vector<long long>(ALPHA, INF));
        for (int i = 0; i < ALPHA; i++) adj[i][i] = 0;

        for (int i = 0; i < cost.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u][v] = min(adj[u][v], (long long)cost[i]);
        }

        shortest_distance(adj, ALPHA); 

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;

            int u = source[i] - 'a', v = target[i] - 'a';
            if (adj[u][v] == INF) return -1;
            ans += adj[u][v];
        }

        return ans;
    }
};
