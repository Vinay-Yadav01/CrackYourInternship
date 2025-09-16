class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> vertical_pts;
        for (auto point : points)
            vertical_pts[point[0]].emplace(point[1]);

        int min_area = INT_MAX;

        for (int pt1 = 0; pt1 < points.size(); pt1++){
            for (int pt2 = pt1 + 1; pt2 < points.size(); pt2++) {
                int x1 = points[pt1][0], y1 = points[pt1][1];
                int x2 = points[pt2][0], y2 = points[pt2][1];

                if (x1 == x2 || y1 == y2)
                    continue;

                if (vertical_pts[x1].count(y2) && vertical_pts[x2].count(y1)) {
                    min_area = min(min_area, (abs(x2 - x1) * abs(y2 - y1)));
                }
            }
        }
        return min_area == INT_MAX ? 0 : min_area;
    }
};