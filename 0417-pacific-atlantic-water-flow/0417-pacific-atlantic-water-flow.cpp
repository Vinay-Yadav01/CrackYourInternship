class Solution {
    void dfs(int r, int c, int m, int n, const vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }

            if (visited[nr][nc]) {
                continue;
            }
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, m, n, heights, visited);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pacificReachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticReachable(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            dfs(r, 0, m, n, heights, pacificReachable);
        }
        for (int c = 0; c < n; ++c) {
            dfs(0, c, m, n, heights, pacificReachable);
        }

        for (int r = 0; r < m; ++r) {
            dfs(r, n - 1, m, n, heights, atlanticReachable);
        }
        for (int c = 0; c < n; ++c) {
            dfs(m - 1, c, m, n, heights, atlanticReachable);
        }

        vector<vector<int>> result;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacificReachable[r][c] && atlanticReachable[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};