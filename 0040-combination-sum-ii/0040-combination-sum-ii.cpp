class Solution {
private:
    void solve(vector<int>& candidates, int ind, int target, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            solve(candidates, i + 1, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, temp, ans);
        return ans;
    }
};