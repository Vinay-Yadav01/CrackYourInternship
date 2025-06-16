class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end());
        long long sum = 0;
        int maxi = maximumHeight[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            maxi = min(maxi, maximumHeight[i]);
            if (maxi == 0)
                return -1;
            sum += maxi;
            maxi--;
        }
        return sum;
    }
};