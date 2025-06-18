class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int maxi = INT_MIN, mini = INT_MAX, n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
            if ((maxi - mini > k) || temp.size() == 3) {
                ans.push_back(temp);
                maxi = nums[i];
                mini = nums[i];
                temp.clear();
            }
            temp.push_back(nums[i]);
        }
        ans.push_back(temp);
        if (ans.size() != n / 3)
            return {};
        return ans;
    }
};