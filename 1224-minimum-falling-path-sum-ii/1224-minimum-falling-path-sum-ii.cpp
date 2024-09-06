class Solution {
    int solve(int i, int last, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (i == 0) {
            int mini = INT_MAX;
            for (int j = 0; j < grid[0].size(); j++) {
                if (j != last)
                    mini = min(mini, grid[i][j]);
            }
            return mini;
        }
        if (dp[i][last] != -1)
            return dp[i][last];
        int mini = INT_MAX;
        for (int j = 0; j < grid[0].size(); j++) {
            if (j != last)
                mini = min(mini, grid[i][j] + solve(i - 1, j, grid, dp));
        }
        return dp[i][last] = mini;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        return solve(n - 1, m, grid, dp);
    }
};