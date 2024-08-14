class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row,
             int col) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            int nRow = q.front().first;
            int nCol = q.front().second;
            q.pop();
            int newR = nRow - 1;
            int newC = nCol;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                grid[newR][newC] != '0' && vis[newR][newC] == 0) {
                vis[newR][newC] = 1;
                q.push({newR, newC});
            }
            newR = nRow;
            newC = nCol - 1;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                grid[newR][newC] != '0' && vis[newR][newC] == 0) {
                vis[newR][newC] = 1;
                q.push({newR, newC});
            }
            newR = nRow;
            newC = nCol + 1;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                grid[newR][newC] != '0' && vis[newR][newC] == 0) {
                vis[newR][newC] = 1;
                q.push({newR, newC});
            }
            newR = nRow + 1;
            newC = nCol;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                grid[newR][newC] != '0' && vis[newR][newC] == 0) {
                vis[newR][newC] = 1;
                q.push({newR, newC});
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] != '0') {
                    cnt++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};