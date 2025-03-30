class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        int i = 0;
        while (i < n) {
            int currStart = intervals[i][0];
            while (i < n && currStart <= prevEnd) {
                prevEnd = max(prevEnd, intervals[i][1]);
                i++;
                if (i < n)
                    currStart = intervals[i][0];
            }
            ans.push_back({prevStart, prevEnd});
            if (i < n) {
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};