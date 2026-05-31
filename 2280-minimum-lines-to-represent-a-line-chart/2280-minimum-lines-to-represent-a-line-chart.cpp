class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n <= 1)
            return 0;

        sort(stockPrices.begin(), stockPrices.end());
        int ans = 1;
        for (int i = 2; i < n; i++) {
            long long x1 = stockPrices[i - 2][0], y1 = stockPrices[i - 2][1];
            long long x2 = stockPrices[i - 1][0], y2 = stockPrices[i - 1][1];
            long long x3 = stockPrices[i][0], y3 = stockPrices[i][1];

            // (y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2)
            // Cross multiplied:
            long long diffY1 = y2 - y1;
            long long diffX1 = x2 - x1;
            long long diffY2 = y3 - y2;
            long long diffX2 = x3 - x2;

            if (diffY1 * diffX2 != diffY2 * diffX1)
                ans++;
        }

        return ans;
    }
};
