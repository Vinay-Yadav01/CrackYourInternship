class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> ans;
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans.push_back(nums[i] * nums[i]);
                i++;
            } else {
                ans.push_back(nums[j] * nums[j]);
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};