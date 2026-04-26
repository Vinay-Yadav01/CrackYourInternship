class Solution {
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(int curX, int curY, int prevX, int prevY,
             vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis[curX][curY] = true;
        for (int i = 0; i < 4; i++) {
            int newX = curX + dir[i].first;
            int newY = curY + dir[i].second;
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                if (grid[newX][newY] == grid[curX][curY]) {
                    if (newX == prevX && newY == prevY)
                        continue;
                    if (vis[newX][newY])
                        return true;
                    if (dfs(newX, newY, curX, curY, vis, grid))
                        return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && dfs(i, j, -1, -1, vis, grid))
                    return true;

        return false;
    }
};