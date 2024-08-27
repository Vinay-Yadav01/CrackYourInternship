class Solution {

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int dist =
                points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (pq.size() < k) {
                pq.push({dist, {points[i][0], points[i][1]}});
            } else {
                if (pq.top().first > dist) {
                    pq.pop();
                    pq.push({dist, {points[i][0], points[i][1]}});
                }
            }
        }
        while (!pq.empty()) {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};