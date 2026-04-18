class Solution {
public:
    int mirrorDistance(int n) {
        long long rev = 0;
        for (int x = n; x > 0; x /= 10) 
            rev = 10 * rev + x % 10;

        return abs(n - rev);
    }
};