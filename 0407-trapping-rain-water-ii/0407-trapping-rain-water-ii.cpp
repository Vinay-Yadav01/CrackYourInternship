class Solution {
#define pip pair<int, pair<int, int>>
    bool isValid(int n, int m, int x, int y) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if (n < 3 || m < 3)
            return 0;
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            minHeap.push({heightMap[i][0], {i, 0}});
            vis[i][0] = 1;
            minHeap.push({heightMap[i][m - 1], {i, m - 1}});
            vis[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            minHeap.push({heightMap[0][j], {0, j}});
            vis[0][j] = 1;
            minHeap.push({heightMap[n - 1][j], {n - 1, j}});
            vis[n - 1][j] = 1;
        }
        int maxHeight = 0;
        int total = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while (!minHeap.empty()) {
            auto it = minHeap.top();
            minHeap.pop();
            int currHeight = it.first;
            maxHeight = max(maxHeight, currHeight);
            int x = it.second.first;
            int y = it.second.second;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (isValid(n, m, newX, newY) && !vis[newX][newY]) {
                    vis[newX][newY] = 1;
                    minHeap.push(
                        {heightMap[newX][newY], {newX, newY}});
                    if (heightMap[newX][newY] < maxHeight) {
                        total +=
                            (maxHeight - heightMap[newX][newY]);
                    }
                }
            }
        }
        return total;
    }
};