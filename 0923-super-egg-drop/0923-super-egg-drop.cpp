class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& dp) {
        if (n <= 1 || k == 1)
            return n;
        if (dp[k][n] != -1)
            return dp[k][n];
        int ans = INT_MAX;
        int l = 1, h = n;
        while (l <= h) {
            int mid = (l + h) / 2;
            int left = solve(k - 1, mid - 1, dp);
            int right = solve(k, n - mid, dp);
            int temp = 1 + max(left, right);
            if (left < right) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
            ans = min(ans, temp); 
        }
        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};