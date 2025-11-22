class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<string, int> mp;
        int count = 0;
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < m; j++) {
                temp += to_string(grid[i][j]) + ",";
            }
            mp[temp]++;
        }
        for (int j = 0; j < m; j++) {
            string temp = "";
            for (int i = 0; i < n; i++) {
                temp += to_string(grid[i][j]) + ",";
            }
            count += mp[temp];
        }
        return count;
    }
};