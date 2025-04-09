class Solution {
#define pip pair<int, pair<int, int>>
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<pip> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k) {
                    pq.push({sum, {i, j}});
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                } else
                    break;
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int i = node.second.first;
            int j = node.second.second;
            ans.push_back({nums1[i], nums2[j]});
        }
        return ans;
    }
};