class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            freeHeap;
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            busyHeap;
        for (int i = 0; i < n; i++)
            freeHeap.push({servers[i], i});

        long long curTime = 0;
        for (int t = 0; t < m; t++) {
            curTime = max(curTime, (long long)t);

            if (freeHeap.empty() && get<0>(busyHeap.top()) > curTime)
                curTime = get<0>(busyHeap.top());

            while (!busyHeap.empty() && get<0>(busyHeap.top()) <= curTime) {
                auto [time, weight, ind] = busyHeap.top();
                busyHeap.pop();
                freeHeap.push({weight, ind});
            }

            auto [weight, idx] = freeHeap.top();
            freeHeap.pop();

            ans[t] = idx;
            busyHeap.push({curTime + tasks[t], weight, idx});
        }
        return ans;
    }
};