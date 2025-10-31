class Solution {
    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int solve(int r, int c, vector<vector<int>>& grid,
              vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        long long cnt = 0;
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        while (!q.empty()) {
            auto [curRow, curCol] = q.front();
            cnt += grid[curRow][curCol];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = curRow + delta[i].first;
                int newCol = curCol + delta[i].second;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] != 0 && !vis[newRow][newCol]) {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return (int)cnt;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    int cnt = solve(i, j, grid, vis);
                    ans += (cnt % k == 0 ? 1 : 0);
                }
            }
        }
        return ans;
    }
};