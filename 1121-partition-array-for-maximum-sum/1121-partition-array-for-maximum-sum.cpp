class Solution {
    int solve(int ind, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();
        if (ind == n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int maxiAns = INT_MIN, maxi = INT_MIN;
        int len = 0;
        for (int j = ind; j < min(n, ind + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = maxi * len + solve(j + 1, arr, k, dp);
            maxiAns = max(maxiAns, sum);
        }
        return dp[ind] = maxiAns;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // int n = arr.size();
        // vector<int> dp(n, -1);
        // return solve(0, arr, k, dp);

        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int maxiAns = INT_MIN, maxi = INT_MIN;
            int len = 0;
            for (int j = ind; j < min(n, ind + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = maxi * len + dp[j+1];
                maxiAns = max(maxiAns, sum);
            }
            dp[ind] = maxiAns;
        }
        return dp[0];
    }
};