class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if (n * m != r * c)
            return mat;

        vector<vector<int>> res(r, vector<int>(c));
        int rInd = 0, cInd = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[rInd][cInd] = mat[i][j];
                cInd++;
                if (cInd == c) {
                    rInd++;
                    cInd = 0;
                }
            }
        }
        return res;
    }
};