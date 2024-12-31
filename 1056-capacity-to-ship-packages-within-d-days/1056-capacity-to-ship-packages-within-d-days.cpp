class Solution {
    int maximum(vector<int>& weights) {
        int maxi = INT_MIN;
        for (int it : weights) {
            maxi = max(maxi, it);
        }
        return maxi;
    }

    int totalWeight(vector<int>& weights) {
        int total = 0;
        for (int it : weights) {
            total += it;
        }
        return total;
    }

    int totalTime(vector<int>& weights, int capacity) {
        int total = 0;
        int days = 1;
        for (int it : weights) {
            total += it;
            if (total > capacity) {
                days++;
                total = it;
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = maximum(weights), e = totalWeight(weights);
        int res = e;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (totalTime(weights, mid) <= days) {
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return res;
    }
};