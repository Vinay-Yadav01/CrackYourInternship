class Solution {
#define pip pair<int, pair<int, int>>
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    minHeap.push({0, {i, j}});
                }
            }
        }
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while (!minHeap.empty()) {
            auto it = minHeap.top();
            minHeap.pop();
            int height = it.first;
            int x = it.second.first;
            int y = it.second.second;
            for (int i = 0; i < 4; i++) {
                int newX = x + dr[i];
                int newY = y + dc[i];
                if (isValid(newX, newY, n, m) && ans[newX][newY] == -1) {
                    ans[newX][newY] = height + 1;
                    minHeap.push({height + 1, {newX, newY}});
                }
            }
        }
        return ans;
    }
};