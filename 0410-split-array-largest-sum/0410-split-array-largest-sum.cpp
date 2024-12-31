class Solution {
    bool isPossible(vector<int>& nums, int n, int k, int pages) {
        int part = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= pages) {
                sum += nums[i];
            } else {
                part++;
                if (part > k || nums[i] > pages)
                    return false;
                sum = nums[i];
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k)
            return -1; 

        long long sum = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (nums[i] > maxi)
                maxi = nums[i];
        }

        long long ans = -1;
        long long s = maxi, e = sum;
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            if (isPossible(nums, n, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};