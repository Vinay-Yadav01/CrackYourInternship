class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int MAX = n * n;
        queue<int> q;
        q.push(1);
        vector<bool> visited(MAX + 1, false);
        visited[1] = true;
        
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                
                if (curr == MAX)
                    return level;
                
                for (int next = curr + 1; next <= min(curr + 6, MAX); ++next) {
                    int dest = next;
                    // Calculate board position
                    int row = (next - 1) / n;
                    int col = (next - 1) % n;
                    if (row % 2 == 1) // Odd rows are right-to-left
                        col = n - 1 - col;
                    
                    row = n - 1 - row; // Convert to board coordinates
                    
                    if (board[row][col] != -1)
                        dest = board[row][col];
                    
                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.push(dest);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};