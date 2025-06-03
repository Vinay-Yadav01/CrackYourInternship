class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        while (i < n) {
            sum += nums[i];
            if (i > 0 && sum % k == 0)
                return true;
            int rem = sum % k;
            if (mp.find(rem) != mp.end()) {
                int ind = mp[rem];
                if (i - ind > 1)
                    return true;
            } else if (mp.find(sum) != mp.end()) {
                int ind = mp[sum];
                if (i - ind > 1)
                    return true;
            } else
                mp[rem] = i;
            i++;
        }
        return false;
    }
};