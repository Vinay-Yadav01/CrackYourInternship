class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> ans = mat;
        int n = mat.size(), m = mat[0].size();
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp;
            for (int r = i, c = 0; r < n && c < m; r++, c++) {
                temp.push_back(mat[r][c]);
            }
            sort(temp.begin(), temp.end());
            int k = 0;
            for (int r = i, c = 0; r < n && c < m; r++, c++) {
                ans[r][c] = temp[k++];
            }
        }
        for (int j = 1; j < m; j++) {
            vector<int> temp;
            for (int r = 0, c = j; r < n && c < m; r++, c++) {
                temp.push_back(mat[r][c]);
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