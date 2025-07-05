class Solution {
    int dp[51][5];

    int solve(int n, int vowelIndex) {
        if (n == 0) return 1;
        if (dp[n][vowelIndex] != -1) return dp[n][vowelIndex];

        int ans = 0;
        for (int i = vowelIndex; i < 5; i++) {
            ans += solve(n - 1, i);
        }

        return dp[n][vowelIndex] = ans;
    }

public:
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);  // Start with all vowels available
    }
};
