class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int ind = 0, n = nums.size();
        while (ind + 1 < n && nums[ind] < nums[ind + 1])
            ind++;
        if (ind == 0 || ind == n - 1)
            return false;
        int p = ind;
        while (ind + 1 < n && nums[ind] > nums[ind + 1])
            ind++;
        if (ind == p || ind == n - 1)
            return false;
        while (ind + 1 < n && nums[ind] < nums[ind + 1])
            ind++;
        return ind == n - 1;
    }
};