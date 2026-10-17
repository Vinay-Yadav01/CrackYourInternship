class Solution {
    bool isValid(int newX, int newY, int m, int n) {
        return newX >= 0 && newX < m && newY >= 0 && newY < n;
    }

public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<char, vector<pair<int, int>>> mp;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] != '.' && matrix[i][j] != '#')
                    mp[matrix[i][j]].push_back({i, j});

        vector<vector<int>> dist(m, vector<int>(n, 1e8));
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        dist[0][0] = 0;
        unordered_set<char> portals;
        while (!q.empty()) {
            auto node = q.front();
            int x = node.first, y = node.second;
            q.pop_front();
            int newDist = 1 + dist[x][y];
            int newX = x - 1, newY = y;

            if (matrix[x][y] != '.' && matrix[x][y] != '#' &&
                (portals.find(matrix[x][y]) == portals.end())) {
                portals.insert(matrix[x][y]);
                for (auto& cell : mp[matrix[x][y]]) {
                    int newX = cell.first, newY = cell.second;
                    if (dist[x][y] < dist[newX][newY]) {
                        dist[newX][newY] = dist[x][y];
                        q.push_front({newX, newY});
                    }
                }
            }

            if (isValid(newX, newY, m, n) && matrix[newX][newY] != '#') {
                if (newDist < dist[newX][newY]) {
                    dist[newX][newY] = newDist;
                    q.push_back({newX, newY});
                }
            }
            newX = x + 1, newY = y;
            if (isValid(newX, newY, m, n) && matrix[newX][newY] != '#') {
                if (newDist < dist[newX][newY]) {
                    dist[newX][newY] = newDist;
                    q.push_back({newX, newY});
                }
            }
            newX = x, newY = y - 1;
            if (isValid(newX, newY, m, n) && matrix[newX][newY] != '#') {
                if (newDist < dist[newX][newY]) {
                    dist[newX][newY] = newDist;
                    q.push_back({newX, newY});
                }
            }
            newX = x, newY = y + 1;
            if (isValid(newX, newY, m, n) && matrix[newX][newY] != '#') {
                if (newDist < dist[newX][newY]) {
                    dist[newX][newY] = newDist;
                    q.push_back({newX, newY});
                }
            }
        }
        return (dist[m - 1][n - 1] != 1e8 ? dist[m - 1][n - 1] : -1);
    }
};