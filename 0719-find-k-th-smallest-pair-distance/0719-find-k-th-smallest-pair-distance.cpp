class Solution {
    int countPairs(int mid, vector<int>& nums) {
        int n = nums.size();
        int count = 0, j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid)
                j++;
            count += (j - i - 1);
        }
        return count;
    };

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        int ans= 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (countPairs(mid, nums) >= k) {
                high = mid - 1;
                ans = mid;
            } else
                low = mid + 1;
        }
        return low;
    }
};
