class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto query : queries) {
            for (int row = query[0]; row <= query[2]; row++) {
                ans[row][query[1]] += 1;
                if (query[3] < n - 1)
                    ans[row][query[3] + 1] -= 1;
            }
        }
        for (int row = 0; row < n; row++) {
            for (int col = 1; col < n; col++) {
                ans[row][col] += ans[row][col - 1];
            }
        }
        return ans;
    }
};