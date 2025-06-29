class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ans = grid;
        int n = grid.size(), m = grid[0].size();
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp;
            for (int r = i, c = 0; r < n && c < m; r++, c++) {
                temp.push_back(grid[r][c]);
            }
            sort(temp.rbegin(), temp.rend());
            int k = 0;
            for (int r = i, c = 0; r < n && c < m; r++, c++) {
                ans[r][c] = temp[k++];
            }
        }
        for (int j = 1; j < m; j++) {
            vector<int> temp;
            for (int r = 0, c = j; r < n && c < m; r++, c++) {
                temp.push_back(grid[r][c]);
            }
            sort(temp.begin(), temp.end());
            int k = 0;
            for (int r = 0, c = j; r < n && c < m; r++, c++) {
                ans[r][c] = temp[k++];
            }
        }
        return ans;
    }
};