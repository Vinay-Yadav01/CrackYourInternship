class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<vector<int>> v(26);

        for (int i = 0; i < s.size(); i++) {
            int len = max(abs(points[i][0]), abs(points[i][1]));
            v[s[i] - 'a'].push_back(len);
        }

        int maxLen = 1e9, ans = 0;

        for (auto& it : v) {
            sort(it.begin(), it.end());
            if (it.size() >= 2) {
                maxLen = min(maxLen, it[1] - 1);
            }
        }

        for (auto& it : v)
            if (it.size() > 0 && it[0] <= maxLen)
                ans++;

        return ans;
    }
};