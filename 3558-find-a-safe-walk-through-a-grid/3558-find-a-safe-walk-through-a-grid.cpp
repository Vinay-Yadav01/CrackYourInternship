class Solution {
    bool isValid(int x, int y, int row, int col) {
        return x >= 0 && x < row && y >= 0 && y < col;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        health -= grid[0][0];
        q.push({{0, 0}, health});

        set<pair<pair<int, int>, int>> vis;
        vis.insert({{0, 0}, health});

        vector<pair<int, int>> delta = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                int x = node.first.first;
                int y = node.first.second;
                int rem = node.second;

                if (x == n - 1 && y == m - 1 && rem >= 1)
                    return true;

                for (auto d : delta) {
                    int newX = x + d.first;
                    int newY = y + d.second;
                    if (isValid(newX, newY, n, m)) {
                        int newK = rem - grid[newX][newY];
                        if (newK >= 1 &&
                            vis.find({{newX, newY}, newK}) == vis.end()) {
                            vis.insert({{newX, newY}, newK});
                            q.push({{newX, newY}, newK});
                        }
                    }
                }
            }
        }
        return false;
    }
};