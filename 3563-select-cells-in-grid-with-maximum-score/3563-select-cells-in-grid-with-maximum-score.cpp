class Solution {
    unordered_map<int, vector<int>> mp;
    int f(int num, int mask, vector<vector<int>>& dp) {
        if (num >= 101) {
            return 0;
        }
        if (dp[num][mask] != -1)
            return dp[num][mask];
        int maxSum = f(num + 1, mask, dp);
        for (const auto& row : mp[num]) {
            if (((1 << row) & mask) == 0) {
                maxSum = max(maxSum, num + f(num + 1, (mask | (1 << row)), dp));
            }
        }
        return dp[num][mask] = maxSum;
    }

public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[grid[i][j]].push_back(i);
            }
        }
        vector<vector<int>> dp(101, vector<int>(1024, -1));
        return f(0, 0, dp);
    }
};