class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long totalRowSum = 0, totalColSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                rowSum[i] += (long long)grid[i][j];
            totalRowSum += rowSum[i];
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++)
                colSum[j] += (long long)grid[i][j];
            totalColSum += colSum[j];
        }

        long long curRowSum = 0, curColSum = 0;
        for (int i = 0; i < m; i++) {
            curRowSum += rowSum[i];
            totalRowSum -= rowSum[i];
            if (curRowSum == totalRowSum)
                return true;
        }

        for (int j = 0; j < n; j++) {
            curColSum += colSum[j];
            totalColSum -= colSum[j];
            if (curColSum == totalColSum)
                return true;
        }
        return false;
    }
};