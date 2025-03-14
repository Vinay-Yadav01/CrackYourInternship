class Solution {
    bool canAssign(long long candieToBeDistributed, vector<int>& candies,
                   long long k) {
        long long count = 0;
        for (auto candie : candies) {
            if (candie >= candieToBeDistributed)
                count += (candie / candieToBeDistributed);
            
        }
        return count >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int max_candies = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canAssign(mid, candies, k)) {
                max_candies = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return max_candies;
    }
};