class Solution {
    int MOD = 1e9 + 7;
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[r][c] != -1)
            return dp[r][c];
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int curCount = 1;
        for (int i = 0; i < 4; i++) {
            int deltaR = r + delta[i].first;
            int deltaC = c + delta[i].second;
            if (deltaR >= 0 && deltaR < n && deltaC >= 0 && deltaC < m &&
                grid[deltaR][deltaC] > grid[r][c]) {
                curCount = (curCount + dfs(deltaR, deltaC, grid, dp)) % MOD;
            }
        }
        return dp[r][c] = curCount;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curCount = dfs(i, j, grid, dp);
                total = (total + dfs(i, j, grid, dp)) % MOD;
            }
        }
        return total;
    }
};