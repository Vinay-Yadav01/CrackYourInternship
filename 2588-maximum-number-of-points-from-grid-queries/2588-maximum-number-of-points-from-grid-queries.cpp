class Solution {
#define pip pair<int, pair<int, int>>
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        set sorted_queries(queries.begin(), queries.end());
        unordered_map<int, int> mp;
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({grid[0][0], {0, 0}});
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for (auto query : sorted_queries) {
            while (!pq.empty()) {
                auto node = pq.top();
                pq.pop();
                int val = node.first;
                int x = node.second.first;
                int y = node.second.second;
                if (val >= query) {
                    pq.push(node);
                    break;
                }
                count++;
                for (int i = 0; i < 4; i++) {
                    int newX = x + dr[i];
                    int newY = y + dc[i];
                    if (isValid(newX, newY, m, n) && !vis[newX][newY]) {
                        vis[newX][newY] = true;
                        pq.push({grid[newX][newY], {newX, newY}});
                    }
                }
            }
            mp[query] = count;
        }
        int size = queries.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++) {
            ans[i] = mp[queries[i]];
        }
        return ans;
    }
};