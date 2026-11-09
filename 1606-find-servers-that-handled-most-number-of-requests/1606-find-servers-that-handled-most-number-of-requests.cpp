class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> availableServers;
        for (int i = 0; i < k; i++)
            availableServers.insert(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busyServer;
        vector<int> reqCount(k, 0);

        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            int id = i % k;
            while (!busyServer.empty() &&
                   busyServer.top().first <= arrival[i]) {
                availableServers.insert(busyServer.top().second);
                busyServer.pop();
            }

            if (availableServers.empty())
                continue;

            auto it = availableServers.lower_bound(id);
            if (it == availableServers.end())
                it = availableServers.begin();

            int availableId = *it;

            availableServers.erase(it);

            reqCount[availableId]++;
            busyServer.push({arrival[i] + load[i], availableId});
        }

        int maxReq = *max_element(reqCount.begin(), reqCount.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
            if (reqCount[i] == maxReq)
                res.push_back(i);

        return res;
    }
};