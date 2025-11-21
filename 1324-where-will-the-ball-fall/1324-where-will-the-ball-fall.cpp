class Solution {
    bool valid(int row, int col, int r, int c) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, int row, int col) {
        if (r == row)
            return c;
        if (valid(row, col, r, c)) {
            if (grid[r][c] == 1) {
                if (valid(row, col, r, c + 1) && grid[r][c + 1] == 1) {
                    return dfs(grid, r + 1, c + 1, row, col);
                }
            } else {
                if (valid(row, col, r, c - 1) && grid[r][c - 1] == -1) {
                    return dfs(grid, r + 1, c - 1, row, col);
                }
            }
        }
        return -1;
    }

public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> ans(col, 0);
        for (int c = 0; c < col; c++) {
            ans[c] = dfs(grid, 0, c, row, col);
        }
        return ans;
    }
};