class Solution {
    void solve(vector<int>& values, int ind, int target, vector<int>& temp,
               vector<vector<int>>& ans, int k) {
        if (target == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if (temp.size() > k || target == 0)
            return;
        for (int i = ind; i < values.size(); i++) {
            if (values[i] > target)
                break;
            temp.push_back(values[i]);
            solve(values, i + 1, target - values[i], temp, ans, k);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        sort(values.begin(), values.end());
        solve(values, 0, n, temp, ans, k);
        return ans;
    }
};