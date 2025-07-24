class Solution {
    void shortest_distance(vector<vector<int>>& matrix, int n) {
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
    vector<int> countOfPairs(int n, int x, int y) {
        x--, y--; // 0-based
        vector<vector<int>> adj(n, vector<int>(n, 1e9));

        // Initialize diagonal and adjacent nodes
        for (int i = 0; i < n; i++)
            adj[i][i] = 0;
        for (int i = 0; i < n - 1; i++) {
            adj[i][i + 1] = 1;
            adj[i + 1][i] = 1;
        }

        // Add extra edge between x and y
        adj[x][y] = adj[y][x] = 1;

        shortest_distance(adj, n);

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int d = adj[i][j];
                if (d < 1e9)
                    ans[d - 1]++;
            }
        }

        return ans;
    }
};
