class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for (auto num : nums) {
            sum = ((sum) % p + (num) % p) % p;
        }
        int target = sum % p;
        if (target == 0)
            return 0;
        int n = nums.size();
        int mini = n;
        unordered_map<int, int> mp;
        int curr = 0;
        mp[curr] = -1;
        for (int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % p;
            int prev = (curr - target + p) % p;
            if (mp.find(prev) != mp.end()) {
                mini = min(mini, i - mp[prev]);
            }
            mp[curr] = i;
        }
        return (mini == n) ? -1 : mini;
    }
};