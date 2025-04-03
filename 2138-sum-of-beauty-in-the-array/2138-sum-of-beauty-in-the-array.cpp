class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMin(n);
        prefixMax[0] = nums[0];
        suffixMin[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        int ans = 0;
        for (int ind = 1; ind < n - 1; ind++) {
            int val = 0;
            if ((prefixMax[ind - 1] < nums[ind]) &&
                (nums[ind] < suffixMin[ind + 1]))
                val = 2;
            else if ((nums[ind - 1] < nums[ind]) && (nums[ind] < nums[ind + 1]))
                val = 1;
            ans += val;
        }
        return ans;
    }
};