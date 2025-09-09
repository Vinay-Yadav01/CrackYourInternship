class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long aware = 0, md = 1e9 + 7;
        vector<long long> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (i - delay >= 0)
                aware = (aware + dp[i - delay]) % md;
            if (i - forget >= 0)
                aware = (aware - dp[i - forget] + md) % md;
            dp[i] = aware;
        }
        long long ans = 0;
        for (int i = n - forget; i < n; i++) {
            ans = (ans + dp[i]) % md;
        }
        return ans;
    }
};