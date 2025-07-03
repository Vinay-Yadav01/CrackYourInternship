class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
            return 0;
        
        grid[r][c] = 0;
        int area = 1;
        
        area += dfs(grid, r + 1, c, n, m);
        area += dfs(grid, r - 1, c, n, m);
        area += dfs(grid, r, c + 1, n, m);
        area += dfs(grid, r, c - 1, n, m);
        
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxArea = 0;  
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1)
                    maxArea = max(maxArea, dfs(grid, i, j, n, m));
            }
        }
        return maxArea;
    }
};
