class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int x = 1; x <= 60; x++) {
            long long rem = num1 - ((long long)x) * num2;
            if (rem < x)
                return -1;
            if (x >= __builtin_popcountll(rem))
                return x;
        }
        return -1;
    }
};