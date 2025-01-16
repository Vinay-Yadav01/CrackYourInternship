class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while (x || y) {
            int bit1 = x & 1;
            int bit2 = y & 1;
            if (bit1 ^ bit2)
                ans++;
            x >>= 1;
            y >>= 1;
        }
        return ans;
    }
};