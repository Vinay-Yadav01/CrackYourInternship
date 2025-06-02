class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int elem = 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = elem++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = elem++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                ans[bottom][i] = elem++;
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                ans[i][left] = elem++;
            }
            left++;
        }
        return ans;
    }
};