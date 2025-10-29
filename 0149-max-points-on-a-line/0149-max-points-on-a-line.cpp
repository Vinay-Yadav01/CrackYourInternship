class Solution {
    double slope(vector<int>& p1, vector<int>& p2) {
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        if (y1 == y2)
            return 0;
        if (x1 == x2)
            return INT_MAX;
        return (double)(y2 - y1) / (double)(x2 - x1);
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1)
            return 1;
        int n = points.size();
        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int samePoint = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0] &&
                    points[i][1] == points[j][1])
                    samePoint++;
                else {
                    double sl = slope(points[i], points[j]);
                    mp[sl]++;
                }
            }
            int localMax = 0;
            for (auto it : mp) {
                localMax = max(localMax, it.second);
            }
            localMax += samePoint;
            maxNum = max(maxNum, localMax);
        }
        return maxNum;
    }
};