class Solution {
    int solve(vector<int>& arr, int n) {
        int max_sum = arr[0], min_sum = arr[0];
        for (int i = 0; i < n; i++) {
            max_sum = max(max_sum, arr[i]);
            min_sum = min(min_sum, arr[i]);
        }
        return (max_sum - min_sum);
    }

public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> sum1(n, 0), diff1(n, 0), sum2(n, 0), diff2(n, 0);
        for (int i = 0; i < n; i++) {
            sum1[i] = arr1[i] + arr2[i] + i;
            diff1[i] = arr1[i] - arr2[i] + i;
            sum2[i] = arr1[i] + arr2[i] - i;
            diff2[i] = arr1[i] - arr2[i] - i;
        }
        return max(
            {solve(sum1, n), solve(diff1, n), solve(sum2, n), solve(diff2, n)});
    }
};