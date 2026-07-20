class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;

        // Strategy 1: Start with an increase (< > < > ...)
        long long k1 = n / 2;
        long long max1 = s;
        if (k1 > 0) {
            max1 = (long long)s + k1 * m - (k1 - 1);
        }

        // Strategy 2: Start with a decrease (> < > < ...)
        long long k2 = (n - 1) / 2;
        long long max2 = (long long)s + k2 * m - k2;

        return max(max1, max2);
    }
};