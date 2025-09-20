class Router {
    set<vector<int>> requestDetail;
    queue<vector<int>> networkRequest;
    int maxLimit;
    unordered_map<int, vector<int>> routerStorage;

public:
    Router(int memoryLimit) { maxLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> newPacket = {source, destination, timestamp};
        if (requestDetail.count(newPacket)) {
            return false;
        }
        if (networkRequest.size() == maxLimit)
            forwardPacket();

        requestDetail.insert(newPacket);
        networkRequest.push({source, destination, timestamp});
        routerStorage[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (networkRequest.empty())
            return {};
        vector<int> ans = networkRequest.front();
        networkRequest.pop();
        requestDetail.erase({ans[0], ans[1], ans[2]});
        routerStorage[ans[1]].erase(routerStorage[ans[1]].begin());

        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = routerStorage.find(destination);
        vector<int>& list = it->second;
        if (it == routerStorage.end() || list.empty())
            return 0;
        auto left = lower_bound(list.begin(), list.end(), startTime);
        auto right = upper_bound(list.begin(), list.end(), endTime);
        return right - left;
    }
};
