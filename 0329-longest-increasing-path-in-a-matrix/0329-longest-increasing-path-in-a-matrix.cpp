class Solution {
    int dfs(int r, int c, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {
        if (dp[r][c] != -1)
            return dp[r][c];
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int curLen = 1;
        for (int i = 0; i < 4; i++) {
            int deltaR = r + delta[i].first;
            int deltaC = c + delta[i].second;
            if (deltaR >= 0 && deltaR < n && deltaC >= 0 && deltaC < m &&
                matrix[deltaR][deltaC] > matrix[r][c]) {
                curLen = max(curLen, 1 + dfs(deltaR, deltaC, matrix, dp));
            }
        }
        return dp[r][c] = curLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curLen = dfs(i, j, matrix, dp);
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};