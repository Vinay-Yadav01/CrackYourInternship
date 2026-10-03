class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] >= intervals[i][0] &&
                    intervals[j][0] <= intervals[i][1])
                    ans++;
            }
        }
        return ans;
    }
};