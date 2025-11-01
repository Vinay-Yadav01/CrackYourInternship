class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        int n = board.size(), m = board[0].size();
        int r = click[0], c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        vector<int> dir = {-1, 0, 1};
        queue<pair<int, int>> q;
        q.push({r, c});
        board[r][c] = 'B'; 
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            int mineCount = 0;
            vector<pair<int, int>> neighbors;

            for (int dr : dir) {
                for (int dc : dir) {
                    if (dr == 0 && dc == 0) continue;
                    int ni = i + dr, nj = j + dc;
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                        if (board[ni][nj] == 'M')
                            mineCount++;
                        else if (board[ni][nj] == 'E')
                            neighbors.push_back({ni, nj});
                    }
                }
            }

            if (mineCount > 0) {
                board[i][j] = '0' + mineCount;
            } else {
                for (auto [ni, nj] : neighbors) {
                    board[ni][nj] = 'B'; 
                    q.push({ni, nj});
                }
            }
        }
        return board;
    }
};
