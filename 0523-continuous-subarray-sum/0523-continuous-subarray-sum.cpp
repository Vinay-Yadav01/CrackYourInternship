class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int i = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        while (i < n) {
            if (i > 0 && prefixSum[i] % k == 0)
                return true;
            int rem = prefixSum[i] % k;
            if (mp.find(rem) != mp.end()) {
                int ind = mp[rem];
                if (i - ind > 1)
                    return true;
            } else if (mp.find(prefixSum[i]) != mp.end()) {
                int ind = mp[prefixSum[i]];
                if (i - ind > 1)
                    return true;
            } else
                mp[rem] = i;
            i++;
        }
        return false;
    }
};