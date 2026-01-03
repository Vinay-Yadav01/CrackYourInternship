class Solution {
    const int MOD = 1e9 + 7;

    int solve(int ind, int n, int prev1, int prev2, int prev3,
              vector<vector<vector<vector<int>>>>& dp) {
        if (ind == n)
            return 1;

        if (dp[ind][prev1][prev2][prev3] != -1)
            return dp[ind][prev1][prev2][prev3];

        int ans = 0;
        for (int curr1 = 0; curr1 < 3; curr1++) {
            for (int curr2 = 0; curr2 < 3; curr2++) {
                for (int curr3 = 0; curr3 < 3; curr3++) {
                    if (curr1 != curr2 && curr2 != curr3 &&
                        curr1 != prev1 && curr2 != prev2 && curr3 != prev3) {
                        ans =
                            (ans + solve(ind + 1, n, curr1, curr2, curr3, dp)) %
                            MOD;
                    }
                }
            }
        }
        return dp[ind][prev1][prev2][prev3] = ans;
    }

public:
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(
            n + 1, vector<vector<vector<int>>>(
                       4, vector<vector<int>>(4, vector<int>(4, -1))));

        return solve(0, n, 3, 3, 3, dp);
    }
};
