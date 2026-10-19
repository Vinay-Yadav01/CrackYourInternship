class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            res = node;
            int x = node[0], y = node[1];
            int newX = x, newY = y;
            if (grid[x][y] == 'L')
                newY = newY - 1;
            else if (grid[x][y] == 'R')
                newY = newY + 1;
            else if (grid[x][y] == 'U')
                newX = newX - 1;
            else
                newX = newX + 1;

            if (newX < 0 || newX >= m || newY < 0 || newY >= n ||
                vis[newX][newY])
                break;

            else {
                q.push({newX, newY});
                vis[newX][newY] = true;
            }
        }
        return res;
    }
};