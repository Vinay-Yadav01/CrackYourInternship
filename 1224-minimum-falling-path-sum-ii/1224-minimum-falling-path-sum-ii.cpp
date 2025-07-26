class Solution {
    int n, m;
    int solve(int row, int prevCol, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (row == 0) {
            int minElement = 1e9;
            for (int j = 0; j < m; j++) {
                if (j != prevCol)
                    minElement = min(minElement, grid[0][j]);
            }
            return minElement;
        }
        if (dp[row][prevCol] != -1)
            return dp[row][prevCol];
        int ans = 1e9;
        for (int j = 0; j < m; j++) {
            if (j != prevCol)
                ans = min(ans, grid[row][j] + solve(row - 1, j, grid, dp));
        }
        return dp[row][prevCol] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        return solve(n - 1, m, grid, dp);
    }
};