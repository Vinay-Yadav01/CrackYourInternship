class Solution {
    int dfs(vector<vector<bool>>& vis, int i, int j) {
        if (i < 0 || j < 0 || i >= vis.size() || j >= vis[0].size() || vis[i][j])
            return 0;
        vis[i][j] = true;
        return 1 + dfs(vis, i - 1, j) + dfs(vis, i + 1, j) +
               dfs(vis, i, j - 1) + dfs(vis, i, j + 1);
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n * 3, vector<bool>(n * 3, false));
        int regions = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    vis[i * 3][j * 3 + 2] = true;
                    vis[i * 3 + 1][j * 3 + 1] = true;
                    vis[i * 3 + 2][j * 3] = true;
                } 
                else if (grid[i][j] == '\\') {
                    vis[i * 3][j * 3] = true;
                    vis[i * 3 + 1][j * 3 + 1] = true;
                    vis[i * 3 + 2][j * 3 + 2] = true;
                }
            }
        }

        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (!vis[i][j]) {
                    dfs(vis, i, j);
                    regions++;
                }
            }
        }
        return regions;
    }
};
