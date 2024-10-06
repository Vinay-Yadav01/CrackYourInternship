class Solution {
    void bfs(int r, int c, vector<vector<char>> board, vector<vector<int>>& vis,
             vector<int> deltaR, vector<int> deltaC) {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        int n = board.size();
        int m = board[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + deltaR[i];
                int newCol = col + deltaC[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    board[newRow][newCol] == 'O' && !vis[newRow][newCol]) {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> deltaR = {-1, 0, 1, 0};
        vector<int> deltaC = {0, 1, 0, -1};
        // Fisrt Row
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i])
                bfs(0, i, board, vis, deltaR, deltaC);
        }

        // Last Column
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O' && !vis[i][m - 1])
                bfs(i, m - 1, board, vis, deltaR, deltaC);
        }

        // Last row
        for (int i = 0; i < m; i++) {
            if (board[n - 1][i] == 'O' && !vis[n - 1][i])
                bfs(n - 1, i, board, vis, deltaR, deltaC);
        }

        // First Column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                bfs(i, 0, board, vis, deltaR, deltaC);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};