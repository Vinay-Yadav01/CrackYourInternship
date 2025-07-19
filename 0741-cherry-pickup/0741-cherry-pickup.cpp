class Solution {
    int solve(int r1, int c1, int r2, int n, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];  // both reach end

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = 0;
        if (r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];  // same cell
        else
            cherries = grid[r1][c1] + grid[r2][c2];

        int a = solve(r1 + 1, c1, r2 + 1, n, grid, dp);
        int b = solve(r1, c1 + 1, r2, n, grid, dp);
        int c = solve(r1 + 1, c1, r2, n, grid, dp);
        int d = solve(r1, c1 + 1, r2 + 1, n, grid, dp);

        int maxNext = max({a, b, c, d});
        if (maxNext < 0)
            return dp[r1][c1][r2] = -1e9;

        return dp[r1][c1][r2] = cherries + maxNext;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = solve(0, 0, 0, n, grid, dp);
        return max(0, ans);
    }
};
