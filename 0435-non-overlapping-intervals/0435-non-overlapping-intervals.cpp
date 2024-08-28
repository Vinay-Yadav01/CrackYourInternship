class Comp {
public:
    bool operator()(vector<int> v1, vector<int> v2) { return v1[1] < v2[1]; }
};
class Solution {

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), Comp());

        int count = 1;
        int n = intervals.size();
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEndTime) {
                count++;
                lastEndTime = intervals[i][1];
            }
        }

        return n - count;
    }
};