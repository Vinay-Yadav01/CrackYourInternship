class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &wall : walls)
            grid[wall[0]][wall[1]] = 1;
        for (auto &guard : guards)
            grid[guard[0]][guard[1]] = 1;

        for (auto &guard : guards) {
            int x = guard[0], y = guard[1];
            // Up
            for (int i = x - 1; i >= 0 && grid[i][y] != 1; i--) {
                if (grid[i][y] == 0) grid[i][y] = 2;
            }
            // Down
            for (int i = x + 1; i < m && grid[i][y] != 1; i++) {
                if (grid[i][y] == 0) grid[i][y] = 2;
            }
            // Left
            for (int j = y - 1; j >= 0 && grid[x][j] != 1; j--) {
                if (grid[x][j] == 0) grid[x][j] = 2;
            }
            // Right
            for (int j = y + 1; j < n && grid[x][j] != 1; j++) {
                if (grid[x][j] == 0) grid[x][j] = 2;
            }
        }

        // Count unguarded cells (0)
        int unguarded = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    unguarded++;

        return unguarded;
    }
};
