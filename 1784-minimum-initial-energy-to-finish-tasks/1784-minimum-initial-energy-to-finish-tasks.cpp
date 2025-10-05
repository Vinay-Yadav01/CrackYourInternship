class Solution {
    int requiredEnergy(vector<vector<int>>& tasks) {
        int total = 0;
        for (auto t : tasks) {
            total += t[1];
        }
        return total;
    }

    bool isPossible(int initialEnergy, vector<vector<int>>& tasks) {
        for (auto t : tasks) {
            if (t[1] > initialEnergy)
                return false;
            initialEnergy -= t[0];
        }
        return true;
    }

public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 int diff_a = a[1] - a[0];
                 int diff_b = b[1] - b[0];
                 if (diff_a != diff_b) {
                     return diff_a > diff_b;
                 }
                 return a[1] > b[1];
             });
        int s = 0, e = requiredEnergy(tasks);
        int ans = e;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(mid, tasks)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};