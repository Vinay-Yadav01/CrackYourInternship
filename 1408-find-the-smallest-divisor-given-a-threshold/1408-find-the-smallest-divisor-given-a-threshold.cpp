class Solution {
    int minimum(vector<int>& nums) {
        int mini = INT_MAX;
        for (int it : nums) {
            mini = min(mini, it);
        }
        return mini;
    }

    int maximum(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int it : nums) {
            maxi = max(maxi, it);
        }
        return maxi;
    }

    int solve(vector<int>& nums, int divisor) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += (nums[i] + divisor - 1) / divisor;
        }
        return ans;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.size() > threshold)
            return -1;
        int s = 1, e = maximum(nums);
        int res = e;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (solve(nums, mid) <= threshold) {
                res = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return res;
    }
};