class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> conv(n);
        int maxi = nums[0];
        conv[0] = nums[0] + maxi;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
            conv[i] = nums[i] + maxi + conv[i - 1];
        }
        return conv;
    }
};