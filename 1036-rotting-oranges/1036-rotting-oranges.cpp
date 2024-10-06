class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int time = 0;
        int oneCount=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j]==1) oneCount++;
            }
        }
        vector<int> deltaRow = {-1, 0, 1, 0};
        vector<int> deltaCol = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                    vis[newRow][newCol] = 1;
                    grid[newRow][newCol] = 2;
                    q.push({{newRow, newCol}, t + 1});
                    oneCount--;
                }
            }
        }
        return (oneCount==0)?time:-1;
    }
};