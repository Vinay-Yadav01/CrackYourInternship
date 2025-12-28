class Solution {
    bool isPossible(vector<int>& time, int totalTrips, long long threshold) {
        long long total = 0;
        for (int t : time) {
            long long trip = threshold / t;
            total += trip;
            if (total >= totalTrips)
                return true;
        }
        return total >= totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long mini = *min_element(time.begin(), time.end());
        long long low = 0, high = mini * totalTrips;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(time, totalTrips, mid)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};