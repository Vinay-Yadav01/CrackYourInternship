class Solution {
public:
    bool isPossible(int x, int y, int n) {
        if (y > x && x >= 0 && x < n && y >= 0 &&
            y < n) { // make sure it lies in upper triangular matrix
            return true;
        }
        return false;
    }
    int maxscore(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp = fruits;
        if (n == 2)
            return dp[0][n - 1];
        if (n == 3)
            return dp[0][n - 1] + dp[1][n - 1];
        for (int i = n - 2; i > 1; i--) {
            for (int j = i + 1; j < n; j++) {
                // (i,j) => (i-1,j-1) (i-1,j) (i-1,j+1)
                int x = i - 1;
                for (int y = j - 1; y <= j + 1; y++) {
                    if (isPossible(x, y, n)) {
                        dp[x][y] = max(dp[x][y], fruits[x][y] + dp[i][j]);
                    }
                }
            }
        }
        return fruits[0][n - 1] + max(dp[1][n - 2], dp[1][n - 1]);
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }
        ans += maxscore(fruits);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(fruits[i][j], fruits[j][i]);
            }
        }
        ans += maxscore(fruits);
        return ans;
    }
};
