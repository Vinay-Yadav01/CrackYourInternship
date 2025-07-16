class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp;
    string search(vector<pair<string, int>>& arr, int timestamp) {
        int l = 0, r = arr.size() - 1;
        string ans = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid].second == timestamp) {
                ans = arr[mid].first;
                break;
            } else if (arr[mid].second < timestamp) {
                ans = arr[mid].first;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        string res = "";
        if (mp.find(key) != mp.end()) {
            res = search(mp[key], timestamp);
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */