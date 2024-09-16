class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minute;
        for (auto time : timePoints) {
            string hour = time.substr(0, 2);
            string min = time.substr(3);
            minute.push_back(stoi(hour) * 60 + stoi(min));
        }
        sort(minute.begin(), minute.end());
        int result = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            result = min(result, minute[i + 1] - minute[i]);
        }
        return min(result, (24 * 60 - minute[n - 1] + minute[0]));
    }
};