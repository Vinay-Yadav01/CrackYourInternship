class Solution {
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, 0), curr(sum + 1, false);
        prev[0] = curr[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[i] <= target)
                    take = prev[target - arr[i]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int N = nums.size();
        for (int i = 0; i < N; i++)
            totalSum += nums[i];
        if (totalSum % 2)
            return false; // Odd Sum
        int sum = totalSum / 2;
        return isSubsetSum(nums, sum);
    }
};