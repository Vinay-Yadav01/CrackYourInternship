class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int start = k - 2; start >= 0; start--) {
            for (int n = 1; n <= k / 3; n++) {
                int incl = slices[start] + dp1[start + 2][n - 1];
                int excl = 0 + dp1[start + 1][n];

                dp1[start][n] = max(incl, excl);
            }
        }
        for (int start = k - 1; start >= 1; start--) {
            for (int n = 1; n <= k / 3; n++) {
                int incl = slices[start] + dp2[start + 2][n - 1];
                int excl = 0 + dp2[start + 1][n];

                dp2[start][n] = max(incl, excl);
            }
        }
        int case1 = dp1[0][k / 3];
        int case2 = dp2[1][k / 3];
        return max(case1, case2);
    }
};