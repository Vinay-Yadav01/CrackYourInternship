class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long, int> mp;
        for (auto row : wall) {
            long long gap = 0;
            for (int i = 0; i < row.size() - 1; ++i) {
                gap += row[i];
                mp[gap]++;
            }
        }

        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, it.second);
        }
        return n - maxi;
    }
};