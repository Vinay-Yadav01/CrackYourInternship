class Solution {
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dist,
             int& thiefCount) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    pq.push({0, {i, j}});
                    dist[i][j] = 0;
                    thiefCount++;
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                    if (dist[newRow][newCol] >
                        d + abs(newRow - row) + abs(newCol - col)) {
                        dist[newRow][newCol] =
                            d + abs(newRow - row) + abs(newCol - col);
                        pq.push({dist[newRow][newCol], {newRow, newCol}});
                    }
                }
            }
        }
    }

    bool isPossible(vector<vector<int>>& dist, int minDist) {
        if (dist[0][0] < minDist)
            return false;
        int n = dist.size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            if (row == n - 1 && col == n - 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    !vis[newRow][newCol] && dist[newRow][newCol] >= minDist) {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int thiefCount = 0;
        bfs(grid, dist, thiefCount);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dist[i][j];
            }
            cout << endl;
        }
        int low = 0, high = 2 * (n - 1), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(dist, mid)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};