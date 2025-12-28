class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int r = m - 1, c = 0, count = 0;
        while (r >= 0 and c < n) {
            if (grid[r][c] < 0) {
                count += n - c;
                r -= 1;
            } else
                c += 1;
        }
        return count;
    }
};