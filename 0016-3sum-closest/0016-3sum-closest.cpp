class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if (sum == target)
                    return sum;
                else if (sum < target) {
                    if (diff < minDiff) {
                        minDiff = diff;
                        ans = sum;
                    }
                    j++;
                } else {
                    if (diff < minDiff) {
                        minDiff = diff;
                        ans = sum;
                    }
                    k--;
                }
            }
        }
        return ans;
    }
};