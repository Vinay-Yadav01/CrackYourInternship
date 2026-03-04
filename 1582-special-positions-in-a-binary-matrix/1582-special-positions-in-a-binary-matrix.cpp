class Solution {
    bool check(int row, int col, int m, int n, vector<vector<int>>& mat) {
        for (int i = 0; i < m; i++) {
            if (i == row)
                continue;
            if (mat[i][col] == 1)
                return false;
        }
        for (int j = 0; j < n; j++) {
            if (j == col)
                continue;
            if (mat[row][j] == 1)
                return false;
        }
        return true;
    }

public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && check(i, j, m, n, mat))
                    ans++;
            }
        }
        return ans;
    }
};