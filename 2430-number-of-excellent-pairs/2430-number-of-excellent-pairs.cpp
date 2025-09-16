class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long cnt[30] = {}, res = 0;
        unordered_set<int> st(begin(nums), end(nums));
        for (int a : st)
            ++cnt[__builtin_popcount(a )];
        for (int i = 1; i < 30; ++i)
            for (int j = 1; j < 30; ++j)
                if (i + j >= k)
                    res += cnt[i] * cnt[j];
        return res;
    }
};