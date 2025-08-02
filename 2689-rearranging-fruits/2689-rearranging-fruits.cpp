class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> f;
        int mn = 1e9;
        for (auto x : basket1) {
            f[x]++;
            mn = min(mn, x);
        }
        for (auto x : basket2) {
            f[x]--;
            mn = min(mn, x);
        }
        vector<int> vec;
        for (auto& [k, v] : f) {
            if (abs(v) % 2 == 1)
                return -1;
            int cnt = abs(v) / 2;
            while (cnt--) {
                vec.push_back(k);
            }
        }
        sort(vec.begin(), vec.end());
        long long ans = 0;
        int swap = 0;
        for (int i = 0; i < vec.size() / 2; i++) {
            if (vec[i] <= 2 * mn) {
                swap += 2;
                ans += vec[i];
            }
        }
        ans += (long long)(vec.size() - swap) * mn;
        return ans;
    }
};