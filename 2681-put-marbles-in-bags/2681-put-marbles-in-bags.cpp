class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> sum;
        int n = weights.size();
        for (int i = 1; i < n; i++) {
            sum.push_back(weights[i] + weights[i - 1]);
        }
        sort(sum.begin(), sum.end());
        long long maxi = 0, mini = 0;
        int sz = sum.size();
        for (int i = 0; i < k - 1; i++) {
            mini += sum[i];
        }
        for (int i = sz - 1; i >= sz - k + 1; i--) {
            maxi += sum[i];
        }
        return maxi - mini;
    }
};