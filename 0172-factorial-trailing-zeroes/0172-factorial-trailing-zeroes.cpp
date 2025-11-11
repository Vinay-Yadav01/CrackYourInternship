class Solution {
public:
    int trailingZeroes(int n) {
        long long twoCount = 0, fiveCount = 0;
        for (int i = 2; i <= n; i++) {
            int num = i;
            while (num % 2 == 0) {
                num /= 2;
                twoCount++;
            }
            while (num % 5 == 0) {
                num /= 5;
                fiveCount++;
            }
        }
        return min(twoCount, fiveCount);
    }
};