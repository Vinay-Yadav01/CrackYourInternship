class Solution {
    vector<long long> dp;
    vector<int> next_ride;
    int size;

    long long attendRide(vector<vector<int>>& rides, int pos) {
        if (pos >= size)
            return 0;
        if (dp[pos] != -1)
            return dp[pos];

        long long skip_ride = attendRide(rides, pos + 1);
        long long next = next_ride[pos];
        long long attend_ride = attendRide(rides, next) + rides[pos][2] +
                                (rides[pos][1] - rides[pos][0]);
        return dp[pos] = max(skip_ride, attend_ride);
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        size = rides.size();
        sort(rides.begin(), rides.end());
        dp.assign(size, -1);
        next_ride = vector<int>(size);
        for (int i = 0; i < size; ++i)
            next_ride[i] = upper_bound(rides.begin() + i, rides.end(),
                                       vector<int>{rides[i][1], 0, 0}) -
                           rides.begin();
        return attendRide(rides, 0);
    }
};