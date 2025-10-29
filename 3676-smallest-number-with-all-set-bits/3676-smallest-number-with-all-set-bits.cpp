class Solution {
public:
    int smallestNumber(int n) {
        int bits = 0;
        while (n > 0) {
            bits++;
            n >>= 1;
        }
        return (1 << bits) - 1;
    }
};