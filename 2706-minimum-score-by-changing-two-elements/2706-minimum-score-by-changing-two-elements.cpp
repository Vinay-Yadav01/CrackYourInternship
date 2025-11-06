class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp = nums;
        temp[0] = temp[1];
        temp[n - 1] = temp[n - 2];
        int minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, temp[i + 1] - temp[i]);
        }
        int maxDiff = temp[n - 1] - temp[0];
        int ans = minDiff + maxDiff;

        temp = nums;
        temp[0] = temp[1] = temp[2];
        minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, temp[i + 1] - temp[i]);
        }
        maxDiff = temp[n - 1] - temp[0];
        ans = min(ans, minDiff + maxDiff);

        temp = nums;
        temp[n - 1] = temp[n - 2] = temp[n - 3];
        minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, temp[i + 1] - temp[i]);
        }
        maxDiff = temp[n - 1] - temp[0];
        ans = min(ans, minDiff + maxDiff);
        return ans;
    }
};