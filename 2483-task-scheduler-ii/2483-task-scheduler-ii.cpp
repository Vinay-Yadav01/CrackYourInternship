class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> nextOk;
        long long day = 0;
        for (int t : tasks) {
            if (nextOk.count(t) && day < nextOk[t]) {
                day = nextOk[t];
            }
            day++;
            nextOk[t] = day + space;
        }
        return day;
    }
};
