class Solution {
    int getMaxLength(int n, vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int count = 1, maxLen = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                count++;
                maxLen = max(maxLen, count);
            } else
                count = 1;
        }
        return maxLen + 1;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int X = getMaxLength(n, hBars);
        int Y = getMaxLength(m, vBars);
        int len = min(X, Y);
        return len * len;
    }
};