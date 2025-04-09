class Solution {
    int binarySearch(vector<vector<int>>& items, int price) {
        int max_beauty = 0;
        int l = 0, h = items.size() - 1;
        int mid;

        while (l <= h) {
            mid = l + (h - l) / 2;
            if (items[mid][0] <= price) {
                max_beauty = max(max_beauty, items[mid][1]);
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return max_beauty;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());

        // Calculate prefix_max_beauty
        for (int i = 1; i < n; ++i)
            items[i][1] = max(items[i - 1][1], items[i][1]);

        vector<int> res;
        for (int i = 0; i < queries.size(); ++i) {
            int max_beauty = binarySearch(items, queries[i]);
            res.push_back(max_beauty);
        }
        return res;
    }
};