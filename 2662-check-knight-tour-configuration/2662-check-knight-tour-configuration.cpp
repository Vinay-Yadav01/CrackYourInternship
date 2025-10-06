class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }

        int n = grid.size();
        int totalMoves = n * n;
        vector<pair<int, int>> movetoCord(totalMoves);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                movetoCord[grid[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < totalMoves - 1; i++) {
            int curRow = movetoCord[i].first, curCol = movetoCord[i].second;
            int nextRow = movetoCord[i + 1].first,
                nextCol = movetoCord[i + 1].second;
            int rowDiff = abs(nextRow - curRow),
                colDiff = abs(nextCol - curCol);
            if ((rowDiff == 2 && colDiff == 1) ||
                (rowDiff == 1 && colDiff == 2))
                continue;
            return false;
        }
        return true;
    }
};