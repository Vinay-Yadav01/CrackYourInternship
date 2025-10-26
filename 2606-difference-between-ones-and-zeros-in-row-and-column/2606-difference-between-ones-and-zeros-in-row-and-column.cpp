class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowOneCount(m, 0), rowZeroCount(m, 0), colZeroCount(n, 0),
            colOneCount(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    rowZeroCount[i]++;
                    colZeroCount[j]++;
                } else {
                    rowOneCount[i]++;
                    colOneCount[j]++;
                }
            }
        }
        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] = rowOneCount[i] + colOneCount[j] - rowZeroCount[i] -
                             colZeroCount[j];
            }
        }
        return diff;
    }
};