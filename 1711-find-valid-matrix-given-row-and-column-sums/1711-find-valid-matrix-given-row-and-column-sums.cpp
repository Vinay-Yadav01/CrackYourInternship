class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (rowSum[i] < colSum[j]) {
                int element = rowSum[i];
                ans[i][j] = element;
                rowSum[i] -= element;
                colSum[j] -= element;
                i++;
            } else {
                int element = colSum[j];
                ans[i][j] = element;
                rowSum[i] -= element;
                colSum[j] -= element;
                j++;
            }
        }
        return ans;
    }
};