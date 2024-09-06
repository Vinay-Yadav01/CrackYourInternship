class Solution {
    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        if (j < 0 || j >= m)
            return 1e8;
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int ld = matrix[i][j] + solve(i - 1, j - 1, n, m, matrix, dp);
        int up = matrix[i][j] + solve(i - 1, j, n, m, matrix, dp);
        int rd = matrix[i][j] + solve(i - 1, j + 1, n, m, matrix, dp);
        return dp[i][j] = min({ld, up, rd});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0), curr(m,0);
        for (int j = 0; j < m; j++)
            prev[j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ld = matrix[i][j];
                if (j - 1 >= 0)
                    ld += prev[j - 1];
                else
                    ld = 1e8;
                int up = matrix[i][j] + prev[j];
                int rd = matrix[i][j];
                if (j + 1 < m)
                    rd += prev[j + 1];
                else
                    rd = 1e8;
                curr[j] = min({ld, up, rd});
            }
            prev = curr;
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};