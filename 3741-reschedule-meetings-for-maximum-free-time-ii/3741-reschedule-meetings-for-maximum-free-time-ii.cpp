class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeGaps;

        freeGaps.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        }
        freeGaps.push_back(eventTime - endTime[n - 1]);

        int m = freeGaps.size();
        vector<int> prefixMax(m), suffixMax(m);

        prefixMax[0] = freeGaps[0];
        for (int i = 1; i < m; ++i)
            prefixMax[i] = max(prefixMax[i - 1], freeGaps[i]);

        suffixMax[m - 1] = freeGaps[m - 1];
        for (int i = m - 2; i >= 0; --i)
            suffixMax[i] = max(suffixMax[i + 1], freeGaps[i]);

        int maxFree = 0;
        for (int i = 0; i + 1 < m; ++i) {
            maxFree = max(maxFree, freeGaps[i] + freeGaps[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            int duration = endTime[i] - startTime[i];
            int mergedGap = freeGaps[i] + freeGaps[i + 1];

            // Try placing meeting somewhere else
            int leftMax = (i > 0) ? prefixMax[i - 1] : -1;
            int rightMax = (i + 2 < m) ? suffixMax[i + 2] : -1;

            if (max(leftMax, rightMax) >= duration) {
                cout<<i<<endl;
                maxFree = max(maxFree, mergedGap + duration);
            }
        }

        return maxFree;
    }
};
