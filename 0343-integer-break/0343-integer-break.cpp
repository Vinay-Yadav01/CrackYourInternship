class Solution {
    int solve(int n, vector<int>& dp) {
        if (n == 1)
            return 1;
        if(dp[n]!=-1) return dp[n];
        int maxi = n;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, i * solve(n - i,dp));
        }
        return dp[n] = maxi;
    }

public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        for (int i = 1; i < n; i++) {
            dp[n] = max(dp[n], i * solve(n - i,dp));
        }
        return dp[n];
    }
};