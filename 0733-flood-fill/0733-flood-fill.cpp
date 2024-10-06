class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ini = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                        !vis[newRow][newCol] && image[newRow][newCol] == ini) {
                    vis[newRow][newCol] = 1;
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};