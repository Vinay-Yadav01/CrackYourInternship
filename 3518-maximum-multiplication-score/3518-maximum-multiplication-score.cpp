class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
                long long dp0 = LONG_MIN, dp1 = LONG_MIN, dp2 = LONG_MIN, dp3 = LONG_MIN;

        for (int i = 0; i < b.size(); i++) {
            // Update dp3, dp2, dp1, and dp0, making sure i0 < i1 < i2 < i3
            if (i >= 3) dp3 = max(dp3, dp2 + 1LL * a[3] * b[i]);
            if (i >= 2) dp2 = max(dp2, dp1 + 1LL * a[2] * b[i]);
            if (i >= 1) dp1 = max(dp1, dp0 + 1LL * a[1] * b[i]);
            dp0 = max(dp0, 1LL * a[0] * b[i]);
        }

        return dp3;
    }
};