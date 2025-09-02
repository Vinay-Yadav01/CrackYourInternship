class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            points[i][1] = -points[i][1];
        }
        sort(points.begin(), points.end());
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = -points[i][1];
            int ymax = -1e9; // bar
            for (int j = i + 1; j < n; j++) {
                int x1 = points[j][0], y1 = -points[j][1];
                if (y1 > ymax && y1 <= y) {
                    ans++;
                    ymax = max(ymax, y1);
                }
            }
        }
        return ans;
    }
};