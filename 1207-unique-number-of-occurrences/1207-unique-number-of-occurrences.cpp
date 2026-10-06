class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int a : arr)
            mp[a]++;
        unordered_set<int> st;
        for(auto& [val, cnt] : mp){
            if(st.find(cnt) != st.end()) return false;
            st.insert(cnt);
        }
        return true;
    }
};