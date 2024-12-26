class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == divisor)
            return 1;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long p = abs((long)dividend);
        long q = abs((long)divisor);
        long quotient = 0;
        while (p >= q) {
            int cnt = 0;
            while (p >= (q << cnt + 1)) {
                cnt++;
            }
            quotient += (1 << cnt);
            p -= (q << cnt);
        }
        if (quotient > INT_MAX && sign == -1)
            return INT_MIN;
        else if (quotient >= INT_MAX && sign == 1)
            return INT_MAX;
        return sign * quotient;
    }
};