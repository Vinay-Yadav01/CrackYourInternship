class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0, colIndex = col - 1;
        while (rowIndex < row && colIndex >= 0) {
            if (matrix[rowIndex][colIndex] == target)
                return true;
            else if (matrix[rowIndex][colIndex] > target)
                colIndex--;
            else
                rowIndex++;
        }
        return false;
    }
};