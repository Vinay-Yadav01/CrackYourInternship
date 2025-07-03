class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size(), m = grid[0].size();
        int currColor = grid[row][col];
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int, int>> borders;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        q.push({row, col});
        vis[row][col] = 1;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            bool isBorder = false;
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (grid[nr][nc] == currColor) {
                        if (!vis[nr][nc]) {
                            q.push({nr, nc});
                            vis[nr][nc] = 1;
                        }
                    } else {
                        isBorder = true;
                    }
                } else {
                    isBorder = true;
                }
            }
            
            if (isBorder) {
                borders.push_back({r, c});
            }
        }
        
        for (auto [r, c] : borders) {
            grid[r][c] = color;
        }
        
        return grid;
    }
};
