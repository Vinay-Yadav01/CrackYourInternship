class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMin(n), suffixMin(n);
        prefixMin[0] = 0;
        suffixMin[n - 1] = n - 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[prefixMin[i - 1]])
                prefixMin[i] = i;
            else
                prefixMin[i] = prefixMin[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[suffixMin[i + 1]])
                suffixMin[i] = i;
            else
                suffixMin[i] = suffixMin[i + 1];
        }
        for (int i = 0; i < n; i++) {
            cout << prefixMin[i] << " " << suffixMin[i] << endl;
        }
        int ans = INT_MAX;
        for (int ind = 1; ind < n - 1; ind++) {
            int leftMin = prefixMin[ind - 1];
            int rightMin = suffixMin[ind + 1];
            
            // Ensure the prefix and suffix minimum elements are strictly less than the current element
            if ((nums[leftMin] < nums[ind]) && (nums[rightMin] < nums[ind])) {
                ans = min(ans, nums[leftMin] + nums[ind] + nums[rightMin]);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};