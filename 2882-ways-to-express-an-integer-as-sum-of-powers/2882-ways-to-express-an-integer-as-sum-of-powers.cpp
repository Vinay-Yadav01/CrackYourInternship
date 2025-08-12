class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(vector<int>& power, int n, int i, int total,
              vector<vector<int>>& dp) {
        if (total == n)
            return 1;
        if (i == power.size() || total + power[i] > n)
            return 0;

        if (dp[i][total] != -1)
            return dp[i][total];

        int take = solve(power, n, i + 1, total + power[i], dp);
        int nottake = solve(power, n, i + 1, total, dp);

        return dp[i][total] = (take + nottake) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int> power;
        int i = 1;
        while (pow(i, x) <= n) {
            power.push_back(pow(i, x));
            i++;
        }
        vector<vector<int>> dp(power.size() + 1, vector<int>(n + 1, -1));
        return solve(power, n, 0, 0, dp);
    }
};