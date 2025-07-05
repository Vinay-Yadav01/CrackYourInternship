class Solution {
    int dp[601][101][101]; // Since constraints: strs.size() ≤ 600, m & n ≤ 100

    int solve(int ind, vector<pair<int, int>>& count, int m, int n) {
        if (ind == count.size())
            return 0;

        if (dp[ind][m][n] != -1)
            return dp[ind][m][n];

        auto [zeroCount, oneCount] = count[ind];
        int take = 0;
        if (zeroCount <= m && oneCount <= n)
            take = 1 + solve(ind + 1, count, m - zeroCount, n - oneCount);
        
        int notTake = solve(ind + 1, count, m, n);

        return dp[ind][m][n] = max(take, notTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> count;
        for (string& s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s)
                (c == '0' ? zeros : ones)++;
            count.emplace_back(zeros, ones);
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, count, m, n);
    }
};
