class Solution {
    int n;
    vector<vector<int>> dp;

    int solve(int ind, int time, vector<int>& satisfaction) {
        if (ind == n) return 0;
        if (dp[ind][time] != -1) return dp[ind][time];

        int take = satisfaction[ind] * time + solve(ind + 1, time + 1, satisfaction);
        int notTake = solve(ind + 1, time, satisfaction);

        return dp[ind][time] = max(take, notTake);
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end()); 
        n = satisfaction.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));  // time can go up to n
        return solve(0, 1, satisfaction);
    }
};
