class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        
        dp[m][n - 1] = dp[m - 1][n] = 1;  // Dummy border for simplicity
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int min_health_on_exit = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, min_health_on_exit - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
