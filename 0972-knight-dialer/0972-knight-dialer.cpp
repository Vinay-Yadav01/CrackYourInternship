class Solution {
    int mod = 1e9 + 7;
    vector<vector<int>> next_move = {{4, 6},    {6, 8}, {7, 9},    {4, 8},
                                     {3, 9, 0}, {},     {1, 7, 0}, {2, 6},
                                     {1, 3},    {2, 4}};
    int solve(int prev, int n, vector<vector<int>>& dp) {
        if (n == 0)
            return 1;
        if (dp[n][prev] != -1)
            return dp[n][prev];
        int ans = 0;
        for (auto next : next_move[prev]) {
            ans = (ans + solve(next, n - 1, dp)) % mod;
        }
        return dp[n][prev] = ans % mod;
    }

public:
    int knightDialer(int n) {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
        for (int i = 0; i <= 9; i++) {
            ans = (ans + solve(i, n - 1, dp)) % mod;
        }
        return ans % mod;
    }
};