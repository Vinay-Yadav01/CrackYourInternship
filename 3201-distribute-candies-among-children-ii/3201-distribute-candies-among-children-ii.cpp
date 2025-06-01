class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > 2 * limit)
                continue;
            ans += max(min(limit, n - i) - max(0, n - i - limit) + 1, 0);
        }
        return ans;
    }
};