class Solution {
public:
    double calc(int a, int b, vector<vector<double>>& dp) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0;
        if (dp[a][b] != -1)
            return dp[a][b];
        double ans = 0;
        ans += 0.25 * calc(a - 100, b, dp);
        ans += 0.25 * calc(a - 75, b - 25, dp);
        ans += 0.25 * calc(a - 50, b - 50, dp);
        ans += 0.25 * calc(a - 25, b - 75, dp);
        dp[a][b] = ans;
        return ans;
    }
    double soupServings(int n) {
        if (n > 5000)
            return 1;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        return calc(n, n, dp);
    }
};