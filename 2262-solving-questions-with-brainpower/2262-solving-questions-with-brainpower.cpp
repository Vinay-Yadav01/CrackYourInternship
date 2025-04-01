class Solution {
    long long f(int ind, vector<vector<int>>& questions,
                vector<long long>& dp) {
        if (ind >= questions.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        long long take =
            questions[ind][0] + f(ind + 1 + questions[ind][1], questions, dp);
        long long notTake = f(ind + 1, questions, dp);
        return dp[ind] = max(take, notTake);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        // int n = questions.size();
        // vector<long long> dp(n + 1, -1);
        // return f(0, questions, dp);
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            long long take = questions[i][0];
            if (i + 1 + questions[i][1] <= n)
                take += dp[i + 1 + questions[i][1]];
            long long notTake = dp[i + 1];
            dp[i] = max(take, notTake);
        }
        return dp[0];
    }
};