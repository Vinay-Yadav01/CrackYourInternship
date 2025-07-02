class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
        long long sum = prefixSum[n - 1];

        for (auto i : prefixSum)
            cout << i << " ";
        vector<long long> ans;
        for (auto it : queries) {
            int ind = lower_bound(nums.begin(), nums.end(), it) - nums.begin();
            if (ind == n or ind == 0)
                ans.push_back(abs((long long)it * n - sum));
            else {
                long long temp =
                    (abs((long long)it * (ind)-prefixSum[ind - 1]));
                temp += (abs((long long)it * (n - ind) -
                             (prefixSum[n - 1] - prefixSum[ind - 1])));
                ans.push_back(temp);
            }
        }
        return ans;
    }
};