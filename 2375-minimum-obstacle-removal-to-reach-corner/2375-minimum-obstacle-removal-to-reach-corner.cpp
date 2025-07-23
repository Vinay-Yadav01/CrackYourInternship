class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        if (grid[0][0] == 0) {
            pq.push({0, {0, 0}});
            dist[0][0] = 0;
        } else {
            pq.push({1, {0, 0}});
            dist[0][0] = 1;
        }

        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int obs = cell.first;
            auto [x, y] = cell.second;
            if (x == m - 1 && y == n - 1)
                return obs;
            for (int i = 0; i < 4; ++i) {
                int newX = x + drow[i];
                int newY = y + dcol[i];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    int newObs = dist[x][y] + ((grid[newX][newY] == 0) ? 0 : 1);
                    if (newObs < dist[newX][newY]) {
                        dist[newX][newY] = newObs;
                        pq.push({newObs, {newX, newY}});
                    }
                }
            }
        }

        return -1;
    }
};