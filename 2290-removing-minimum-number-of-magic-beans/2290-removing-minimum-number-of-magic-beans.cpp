class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL);
        long long ans = LLONG_MAX;
        int n = beans.size();
        for (int i = 0; i < n; i++) {
            long long curr = total - (long long)(n - i) * beans[i];
            ans = min(curr, ans);
        }
        return ans;
    }
};