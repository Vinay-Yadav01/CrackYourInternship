class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (firstList[i][1] < secondList[j][0])
                ++i;
            else if (secondList[j][1] < firstList[i][0])
                ++j;
            else {
                ans.push_back({max(firstList[i][0], secondList[j][0]),
                               min(firstList[i][1], secondList[j][1])});
                if (firstList[i][1] < secondList[j][1])
                    ++i;
                else
                    ++j;
            }
        }
        return ans;
    }
};