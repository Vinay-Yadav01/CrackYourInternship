class Solution {
    void bfs(int r, int c, vector<vector<int>> grid, vector<vector<int>>& vis,
             vector<int> deltaR, vector<int> deltaC) {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + deltaR[i];
                int newCol = col + deltaC[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> deltaR = {-1, 0, 1, 0};
        vector<int> deltaC = {0, 1, 0, -1};
        // Fisrt Row
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i])
                bfs(0, i, grid, vis, deltaR, deltaC);
        }

        // Last Column
        for (int i = 0; i < n; i++) {
            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                bfs(i, m - 1, grid, vis, deltaR, deltaC);
        }

        // Last row
        for (int i = 0; i < m; i++) {
            if (grid[n - 1][i] == 1 && !vis[n - 1][i])
                bfs(n - 1, i, grid, vis, deltaR, deltaC);
        }

        // First Column
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0])
                bfs(i, 0, grid, vis, deltaR, deltaC);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};