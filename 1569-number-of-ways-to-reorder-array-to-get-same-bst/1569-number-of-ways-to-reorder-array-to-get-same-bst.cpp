class Solution {
    typedef long long ll;
    ll MOD = 1e9 + 7;
    vector<vector<ll>> PT;

    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 1;
        vector<int> leftArr, rightArr;
        for (int i = 1; i < n; i++)
            if (nums[i] < nums[0])
                leftArr.push_back(nums[i]);
            else
                rightArr.push_back(nums[i]);

        ll leftAns = (solve(leftArr)) % MOD;
        ll rightAns = (solve(rightArr)) % MOD;
        ll comb = PT[n - 1][leftArr.size()];

        return ((leftAns * rightAns) % MOD * comb) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        PT.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            PT[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                PT[i][j] = (PT[i - 1][j] + PT[i - 1][j - 1]) % MOD;
            }
        }
        return (solve(nums) - 1 + MOD) % MOD;
    }
};