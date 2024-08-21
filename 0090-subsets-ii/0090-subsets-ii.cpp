class Solution {
private:
    void solve(vector<int>& nums, int ind, vector<int> &temp,
               vector<vector<int>> &ans) {
        ans.push_back(temp);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, 0, temp, ans);
        return ans;
    }
};