class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int a : arr)
            mp[a]++;
        vector<pair<int, int>> freq;
        for (auto it : mp) {
            cout<<it.first<<" "<<it.second<<endl;
            freq.push_back({it.second, it.first});
        }
        sort(freq.begin(), freq.end());
        int n = freq.size(), ind = 0;
        while (ind < n && k > 0) {
            if (k < freq[ind].first)
                break;
            k -= freq[ind].first;
            ind++;
        }
        return n - ind;
    }
};