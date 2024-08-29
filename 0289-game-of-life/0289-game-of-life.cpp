class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int oneCount = 0;

                // Checking all 8 neighbors
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 && l == 0)
                            continue; // Skip the cell itself

                        int ni = i + k, nj = j + l;

                        // Check if the neighbor is within bounds
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            if (board[ni][nj] == 1) {
                                oneCount++;
                            }
                        }
                    }
                }

                // Applying the rules of the Game of Life
                if (board[i][j] == 1) {
                    if (oneCount < 2 || oneCount > 3) {
                        temp[i][j] = 0; // Cell dies
                    }
                } else {
                    if (oneCount == 3) {
                        temp[i][j] = 1; // Cell becomes alive
                    }
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = temp[i][j];
            }
        }
        return;
    }
};