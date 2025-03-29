class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        int i = 0, j = 0;
        bool upSide = true;
        
        while (ans.size() < n * m) {
            ans.push_back(mat[i][j]);

            if (upSide) {  // Moving up
                if (j == m - 1) {  // Reached last column
                    i++;
                    upSide = false;
                } else if (i == 0) {  // Reached first row
                    j++;
                    upSide = false;
                } else {
                    i--; j++;
                }
            } else {  // Moving down
                if (i == n - 1) {  // Reached last row
                    j++;
                    upSide = true;
                } else if (j == 0) {  // Reached first column
                    i++;
                    upSide = true;
                } else {
                    i++; j--;
                }
            }
        }
        return ans;
    }
};
