class Solution {
    bool ifPossible(long long time, vector<int>& ranks, int cars) {
        long long count = 0;
        for (long long rank : ranks)
            count += sqrt(time / rank);

        return count >= cars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high =((long long)*min_element(ranks.begin(), ranks.end())) *
                                  ((long long)cars * (long long)cars);
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (ifPossible(mid, ranks, cars)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};