class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q; // Storing Index of Maximum Element
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() <= (i - k)) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};