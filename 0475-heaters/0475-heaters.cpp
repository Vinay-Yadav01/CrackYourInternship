class Solution {
    bool isPossible(vector<int>& houses, vector<int>& heaters, int dist) {
        int n = houses.size(), m = heaters.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (abs(houses[i] - heaters[j]) <= dist) i++;
            else
                j++;
        }
        return i == n;
    }

public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int low = 0, high = max(heaters.back(), houses.back());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(houses, heaters, mid)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};