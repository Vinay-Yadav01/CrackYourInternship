class Solution {
private:
    void bfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row,
             int col) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = board.size();
        int m = board[0].size();
        vector<int> deltaR = {-1, 0, 1, 0};
        vector<int> deltaC = {0, 1, 0, -1};
        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = currRow + deltaR[i];
                int newCol = currCol + deltaC[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    board[newRow][newCol] == 'X' && vis[newRow][newCol] == 0) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && board[i][j] == 'X') {
                    cnt++;
                    bfs(board, vis, i, j);
                }
            }
        }
        return cnt;
    }
};