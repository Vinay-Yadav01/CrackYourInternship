class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        vector<int> odd_presum(n + 1, 0), even_presum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                odd_presum[i + 1] = odd_presum[i] + nums[i];
                even_presum[i + 1] = even_presum[i];
            } else {
                even_presum[i + 1] = even_presum[i] + nums[i];
                odd_presum[i + 1] = odd_presum[i];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int odd_sum1 = odd_presum[i - 1];
            int even_sum1 = even_presum[i - 1];

            int even_sum2 = odd_presum[n] - odd_presum[i];
            int odd_sum2 = even_presum[n] - even_presum[i];

            if (odd_sum1 + odd_sum2 == even_sum1 + even_sum2)
                ans++;
        }
        return ans;
    }
};