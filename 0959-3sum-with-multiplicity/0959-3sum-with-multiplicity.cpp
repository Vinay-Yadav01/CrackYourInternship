class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        int MOD = (int)(1e9 + 7);
        int ans = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            ans = (ans + mp[target - arr[i]]) % MOD;
            for (int j = 0; j < i; j++) {
                mp[arr[i] + arr[j]]++;
            }
        }
        return ans;
    }
};