class Solution {
    int solve(vector<int>& arr, int ind, unordered_map<int, int>& mp,
              vector<int>& dp) {
        if (ind < 0)
            return 0;
        if (ind == 0)
            return arr[ind] * mp[arr[ind]];
        if (dp[ind] != -1)
            return dp[ind];
        int ans = 0;
        if (arr[ind - 1] != arr[ind] - 1)
            ans = arr[ind] * mp[arr[ind]] + solve(arr, ind - 1, mp, dp);
        else
            ans = max(arr[ind] * mp[arr[ind]] + solve(arr, ind - 2, mp, dp),
                      solve(arr, ind - 1, mp, dp));
        return dp[ind] = ans;
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr;
        unordered_map<int, int> mp;
        for (int num : nums) {
            if (mp[num] == 0)
                arr.push_back(num);
            mp[num]++;
        }
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, -1);
        return solve(arr, n - 1, mp, dp);
    }
};