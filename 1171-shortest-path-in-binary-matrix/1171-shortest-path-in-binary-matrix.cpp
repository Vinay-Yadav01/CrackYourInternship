class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // Edge case: If source or destination is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int wt = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // Early exit if destination is reached
            if (x == n - 1 && y == n - 1) {
                return wt + 1; //+1 is only change
            }

            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int newRow = x + dr;
                    int newCol = y + dc;

                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < n && grid[newRow][newCol] == 0) {
                        if (dist[newRow][newCol] > wt + 1) {
                            dist[newRow][newCol] = wt + 1;
                            q.push({dist[newRow][newCol], {newRow, newCol}});
                        }
                    }
                }
            }
        }

        // If BFS completes and destination is still unreachable, return -1
        return -1;
    }
};