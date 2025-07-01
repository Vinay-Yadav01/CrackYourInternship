class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<long long, int> mp;
        int ans = 0;

        for (auto& coord : coordinates) {
            int x = coord[0], y = coord[1];

            for (int a = 0; a <= k; ++a) {
                int b = k - a;
                int x1 = x ^ a;
                int y1 = y ^ b;

                // Convert (x1, y1) to a single key
                
                // (long long)x1 → promote x1 to 64 - bit to avoid overflow
                // during shift.
                // << 32 → shift x1 left by 32 bits.
                // | y1 → bitwise OR with y1
                // This means:
                //     The upper 32 bits hold x1,
                //     The lower 32 bits hold y1.

                long long key = ((long long)x1 << 32) | y1;
                ans += mp[key];
            }

            // Store current (x, y) in map
            long long key = ((long long)x << 32) | y;
            mp[key]++;
        }

        return ans;
    }
};
