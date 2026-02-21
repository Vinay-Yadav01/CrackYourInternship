class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0), suf(n + 1, 0);
        long long res = 0;
        long long p = 1LL << k;

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] | nums[i];
            suf[n - i - 1] = suf[n - i] | nums[n - i - 1];
        }

        for (int i = 0; i < n; i++)
            res = max(res, pre[i] | (nums[i] * p) | suf[i + 1]);

        return res;
    }
};