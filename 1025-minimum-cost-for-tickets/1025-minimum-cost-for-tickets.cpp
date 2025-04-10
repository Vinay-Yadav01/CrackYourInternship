class Solution {
    int solve(int ind, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        int n = days.size();
        if (ind == n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int op1 = costs[0] + solve(ind + 1, days, costs, dp);
        int i = ind;
        while (i < n && days[i] < days[ind] + 7) {
            i++;
        }
        int op2 = costs[1] + solve(i, days, costs, dp);
        i = ind;
        while (i < n && days[i] < days[ind] + 30) {
            i++;
        }
        int op3 = costs[2] + solve(i, days, costs, dp);
        return dp[ind] = min({op1, op2, op3});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, days, costs, dp);
    }
};