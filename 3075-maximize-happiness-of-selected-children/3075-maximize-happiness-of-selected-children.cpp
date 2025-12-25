class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans = 0, factor = 0;
        for (int i = 0; i < k; i++) {
            if (happiness[i] < factor)
                break;
            ans += (long long)happiness[i] - factor;
            factor++;
        }
        return ans;
    }
};