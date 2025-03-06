class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = pow(n, 2) + 1;
        vector<int> arr(size, 0);
        for (auto it : grid) {
            for (int i : it) {
                arr[i]++;
            }
        }
        vector<int> ans(2, 0);
        for (int i = 1; i < size; i++) {
            if (arr[i] == 0)
                ans[1] = i;
            if (arr[i] == 2)
                ans[0] = i;
        }
        return ans;
    }
};