class Solution {
    bool dfs(vector<vector<int>>& grid, int r, int c, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m)
            return false;
        if (grid[r][c] == 1)
            return true;
        grid[r][c] = 1;
        bool left = dfs(grid, r - 1, c, n, m);
        bool right = dfs(grid, r + 1, c, n, m);
        bool up = dfs(grid, r, c - 1, n, m);
        bool down = dfs(grid, r, c + 1, n, m);
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int countIsland = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    countIsland += dfs(grid, i, j, n, m);
                }
            }
        }
        return countIsland;
    }
};