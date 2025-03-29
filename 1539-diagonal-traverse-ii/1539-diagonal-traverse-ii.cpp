class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size();
        vector<pair<int, pair<int, int>>> arr;
        // Store elements in the map, grouped by (i + j)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                arr.push_back({i + j, {j, i}});
            }
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        // Extract values in diagonal order
        for (auto it : arr) {
            int col = it.second.first;
            int row = it.second.second;
            ans.push_back(nums[row][col]);
        }
        return ans;
    }
};
