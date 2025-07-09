class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeArray;
        freeArray.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            freeArray.push_back(startTime[i] - endTime[i - 1]);
        }
        freeArray.push_back(eventTime - endTime[n - 1]);

        int m = freeArray.size(), currSum = 0, maxSum = 0;
        for (int i = 0; i < m; i++) {
            currSum += freeArray[i];
            if (i >= k + 1)
                currSum -= freeArray[i - (k + 1)];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};