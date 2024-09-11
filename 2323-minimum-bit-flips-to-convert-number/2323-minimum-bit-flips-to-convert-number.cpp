class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while (start || goal) {
            int bit1 = start & 1;
            int bit2 = goal & 1;
            if (bit1 ^ bit2)
                ans++;
            start >>= 1;
            goal >>= 1;
        }
        return ans;
    }
};