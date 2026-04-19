class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        sort(sources.begin(), sources.end(), [](auto &a, auto &b){
            return a[2] > b[2];
        });

        queue<vector<int>> q;
        for (auto &s : sources) {
            q.push({s[0], s[1], s[2]});
            grid[s[0]][s[1]] = s[2];
            vis[s[0]][s[1]] = 1;
        }

        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!q.empty()) {
            auto top = q.front(); q.pop();
            int x = top[0], y = top[1], c = top[2];
            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (vis[nx][ny] == 1 || grid[nx][ny] > c) continue;

                grid[nx][ny] = c;
                vis[nx][ny] = 1;
                q.push({nx, ny, c});
            }
        }

        return grid;
    }
};