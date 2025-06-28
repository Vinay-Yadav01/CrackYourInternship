class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(), i = 0;
        vector<int> ans;
        while (i < k) {
            ans.push_back(nums[i]);
            i++;
        }

        while (i < n) {
            int mini = min_element(ans.begin(), ans.end()) - ans.begin();
            if (ans[mini] < nums[i]) {
                ans.erase(ans.begin() + mini);
                ans.push_back(nums[i]);
            }
            i++;
        }
        return ans;
    }
};