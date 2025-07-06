class Solution {
    // int solve(vector<int>& arr, int ind, unordered_map<int, int>& mp,
    //           vector<int>& dp) {
    //     if (ind < 0)
    //         return 0;
    //     if (ind == 0)
    //         return arr[ind] * mp[arr[ind]];
    //     if (dp[ind] != -1)
    //         return dp[ind];
    //     int ans = 0;
    //     if (arr[ind - 1] != arr[ind] - 1)
    //         ans = arr[ind] * mp[arr[ind]] + solve(arr, ind - 1, mp, dp);
    //     else
    //         ans = max(arr[ind] * mp[arr[ind]] + solve(arr, ind - 2, mp, dp),
    //                   solve(arr, ind - 1, mp, dp));
    //     return dp[ind] = ans;
    // }

public:
    int deleteAndEarn(vector<int>& nums) {
        // vector<int> arr;
        // unordered_map<int, int> mp;
        // for (int num : nums) {
        //     if (mp[num] == 0)
        //         arr.push_back(num);
        //     mp[num]++;
        // }
        // int n = arr.size();
        // sort(arr.begin(), arr.end());
        // vector<int> dp(n, -1);
        // return solve(arr, n - 1, mp, dp);

        // vector<int> arr;
        // unordered_map<int, int> mp;
        // for (int num : nums) {
        //     if (mp[num] == 0)
        //         arr.push_back(num);
        //     mp[num]++;
        // }
        // int n = arr.size();
        // sort(arr.begin(), arr.end());
        // vector<int> dp(n + 1, 0);
        // dp[0] = 0, dp[1] = arr[0] * mp[arr[0]];
        // for (int ind = 2; ind <= n; ind++) {
        //     int ans = 0;
        //     int i = ind - 1;
        //     if (arr[i - 1] != arr[i] - 1)
        //         ans = arr[i] * mp[arr[i]] + dp[ind - 1];
        //     else
        //         ans = max(arr[i] * mp[arr[i]] + dp[ind - 2], dp[ind - 1]);
        //     dp[ind] = ans;
        // }
        // return dp[n];

        vector<int> arr;
        unordered_map<int, int> mp;
        for (int num : nums) {
            if (mp[num] == 0)
                arr.push_back(num);
            mp[num]++;
        }
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int prev2 = 0, prev1 = 0;
        for (int ind = 0; ind < n; ind++) {
            int ans = 0;
            if (ind > 0 && arr[ind - 1] != arr[ind] - 1)
                ans = arr[ind] * mp[arr[ind]] + prev1;
            else
                ans = max(arr[ind] * mp[arr[ind]] + prev2, prev1);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};