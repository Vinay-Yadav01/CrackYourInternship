class Solution {
    int minimum(vector<int>& bloomDay) {
        int mini = INT_MAX;
        for (int it : bloomDay) {
            mini = min(mini, it);
        }
        return mini;
    }

    int maximum(vector<int>& bloomDay) {
        int maxi = INT_MIN;
        for (int it : bloomDay) {
            maxi = max(maxi, it);
        }
        return maxi;
    }

    int bouquet(vector<int>& bloomDay, int k, int day) {
        int no = 0;
        int size = bloomDay.size();
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (bloomDay[i] <= day)
                cnt++;
            else {
                no += (cnt / k);
                cnt = 0;
            }
        }
        no += (cnt / k);
        return no;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((1LL * m * k) > bloomDay.size())
            return -1;
        int s = minimum(bloomDay);
        int e = maximum(bloomDay);
        int res = e;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (bouquet(bloomDay, k, mid) >= m) {
                res = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return res;
    }
};