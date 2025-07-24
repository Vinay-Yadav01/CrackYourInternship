class Solution {
    bool dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vis[r][c] = 1;

        bool isSubIsland = (grid1[r][c] == 1); // valid only if grid1 also has land here

        vector<pair<int, int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto [dr, dc] : delta) {
            int newRow = r + dr, newCol = c + dc;
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !vis[newRow][newCol] && grid2[newRow][newCol] == 1) {
                // combine results using logical AND
                isSubIsland &= dfs(newRow, newCol, vis, grid1, grid2);
            }
        }

        return isSubIsland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    if (dfs(i, j, vis, grid1, grid2)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
