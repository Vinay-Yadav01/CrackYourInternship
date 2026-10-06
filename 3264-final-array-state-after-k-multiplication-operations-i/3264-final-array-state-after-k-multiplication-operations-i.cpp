class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});
        while (k--) {
            auto it = pq.top();
            pq.pop();
            int num = it.first;
            int ind = it.second;
            pq.push({num * multiplier, ind});
        }

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int num = it.first;
            int ind = it.second;
            nums[ind] = num;
        }
        return nums;
    }
};