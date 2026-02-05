class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int j = 0, n = nums.size();
        int sum = 0, res = n + 1;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end()) {
                sum += nums[i];
            }
            mp[nums[i]]++;
            while (sum >= k) {
                res = min(res, i - j + 1);
                mp[nums[j]]--;
                if (mp[nums[j]] == 0) {
                    sum -= nums[j];
                    mp.erase(nums[j]);
                }
                j++;
            }
        }
        return res == n + 1 ? -1 : res;
    }
};