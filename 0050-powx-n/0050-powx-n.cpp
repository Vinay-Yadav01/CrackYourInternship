class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        long m = n;
        if (n < 0)
            m = -m;
        double ans = 1.0;
        while (m > 0) {
            if (m & 1) { // Odd
                ans = ans * x;
                m = m - 1;
            } else {
                x = x * x;
                m = m / 2;
            }
        }
        if (n < 0)
            return 1.0 / ans;
        return ans;
    }
};