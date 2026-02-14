class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row == 0)
            return poured > 0;
        vector<double> prev = {1.0 * poured};
        int ind = 0;
        while (prev.size() < query_row + 1) {
            int n = prev.size();
            vector<double> curr(n + 1, 0);
            curr[0] = (prev[0] > 1 ? (prev[0] - 1) / 2 : 0);
            curr[n] = (prev[n - 1] > 1 ? (prev[n - 1] - 1) / 2 : 0);

            for (int i = 1; i < n; i++) {
                curr[i] = (prev[i] > 1 ? (prev[i] - 1) / 2 : 0);
                curr[i] += (prev[i - 1] > 1 ? (prev[i - 1] - 1) / 2 : 0);
            }

            prev = curr;
        }
        return prev[query_glass] > 1 ? 1.0 : prev[query_glass];
    }
};