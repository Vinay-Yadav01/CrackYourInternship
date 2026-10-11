class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (auto& index : indices) {
            int x = index[0], y = index[1];
            for (int i = 0; i < m; i++)
                res[i][y]++;

            for (int j = 0; j < n; j++)
                res[x][j]++;
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (res[i][j] % 2 == 1)
                    cnt++;

        return cnt;
    }
};