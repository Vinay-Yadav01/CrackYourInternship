class Solution {
    const int MOD = 1e9 + 7;
    int solve(int i, int j, int prev, int m, int n, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j][prev + 1] != -1)
            return dp[i][j][prev + 1];

        if (grid[i][j] == 1) {
            if (prev == 0) // 0->down, 1->right
                return dp[i][j][prev + 1] = solve(i, j + 1, 1, m, n, grid, dp);
            else if (prev == 1)
                return dp[i][j][prev + 1] = solve(i + 1, j, 0, m, n, grid, dp);
        }
        return dp[i][j][prev + 1] = (solve(i, j + 1, 1, m, n, grid, dp) +
                                     solve(i + 1, j, 0, m, n, grid, dp)) %
                                    MOD;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1)));
        return solve(0, 0, -1, m, n, grid, dp);
    }
};