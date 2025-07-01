class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, pair<int, int>>> diffArray;
        for (auto cost : costs) {
            diffArray.push_back({cost[0] - cost[1], {cost[0], cost[1]}});
        }
        sort(diffArray.begin(), diffArray.end());
        int ans = 0;
        for (int i = 0; i < diffArray.size(); i++) {
            if (i < (diffArray.size() / 2))
                ans += diffArray[i].second.first;
            else
                ans += diffArray[i].second.second;
        }
        return ans;
    }
};