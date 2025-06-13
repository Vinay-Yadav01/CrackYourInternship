class Solution {
    int countPairs(vector<int>& nums, int diff) {
        int cnt = 0;
        int i = 0, n = nums.size();
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= diff) {
                cnt++;
                i += 2;
            } else
                i++;
        }
        return cnt;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        int result = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (countPairs(nums, mid) >= p) {
                result = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return result;
    }
};