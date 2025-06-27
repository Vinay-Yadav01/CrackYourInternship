class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int> dp(n + 1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            char ch = pressedKeys[i - 1];
            dp[i] = dp[i - 1];
            if ((i >= 2) && pressedKeys[i - 2] == ch)
                dp[i] = (dp[i] + dp[i - 2]) % mod;
            else
                continue;

            if ((i >= 3) && pressedKeys[i - 3] == ch)
                dp[i] = (dp[i] + dp[i - 3]) % mod;
            else
                continue;
                
            if ((i >= 4) && (ch == '7' || ch == '9') &&
                pressedKeys[i - 4] == ch)
                dp[i] = (dp[i] + dp[i - 4]) % mod;
        }
        return (dp[n] % mod);
    }
};