class Solution {
    vector<int> solve(int r, int c, vector<vector<int>>& vis,
                      vector<vector<int>>& land) {
        vector<int> cord;
        cord.push_back(r);
        cord.push_back(c);
        int row = r, col = c;
        queue<pair<int, int>> q;
        int m = land.size(), n = land[0].size();
        q.push({r, c});
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            int newRow = row + 1, newCol = col;
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !vis[newRow][newCol] && land[newRow][newCol] == 1) {
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
            newRow = row, newCol = col + 1;
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !vis[newRow][newCol] && land[newRow][newCol] == 1) {
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
        cord.push_back(row);
        cord.push_back(col);
        return cord;
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1 && !vis[i][j]) {
                    vector<int> temp = solve(i, j, vis, land);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};