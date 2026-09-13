class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            vector<int> row(n);
            int k = rowShift[i];
            for (int j = 0; j < n; j++) {
                row[j] = grid[i][(j + k) % n];
            }
            for (int j = 0; j < n; j++) {
                grid[i][j] = row[j];
            }
        }

        for (int j = 0; j < n; j++) {
            vector<int> col(n);
            int k = colShift[j];
            for (int i = 0; i < n; i++) {
                col[i] = (grid[(i + k) % n][j]);
            }
            for (int i = 0; i < n; i++) {
                grid[i][j] = col[i];
            }
        }
        return grid;
    }
};