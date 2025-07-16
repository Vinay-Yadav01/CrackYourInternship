class Solution {
    int lower_bound_pair(vector<pair<int, int>>& arr, int key) {
        int s = 0, e = arr.size() - 1;
        int ans = arr.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid].first >= key) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> sortedIndex;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            sortedIndex.push_back({intervals[i][0], i});
        }
        sort(sortedIndex.begin(), sortedIndex.end());
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int ind = lower_bound_pair(sortedIndex, intervals[i][1]);
            if (ind != sortedIndex.size()) {
                ans[i] = sortedIndex[ind].second;
            }
        }
        return ans;
    }
};