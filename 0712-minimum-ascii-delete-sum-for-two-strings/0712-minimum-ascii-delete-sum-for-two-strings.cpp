class Solution {
    int solve(int ind1, int ind2, string& s1, string& s2,
              vector<vector<int>>& dp) {
        if (ind1 < 0 && ind2 < 0)
            return 0;
        if (ind1 < 0) {
            int temp = 0;
            while (ind2 >= 0)
                temp += s2[ind2--];
            return temp;
        }
        if (ind2 < 0) {
            int temp = 0;
            while (ind1 >= 0)
                temp += s1[ind1--];
            return temp;
        }
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s1, s2, dp);
        return dp[ind1][ind2] =
                   min(s1[ind1] + solve(ind1 - 1, ind2, s1, s2, dp),
                       s2[ind2] + solve(ind1, ind2 - 1, s1, s2, dp));
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s1, s2, dp);
    }
};