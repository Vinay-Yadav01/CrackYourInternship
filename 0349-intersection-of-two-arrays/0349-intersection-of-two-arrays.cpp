class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int num: nums1){
            mp[num]++;
        }
        set<int> st;
        for(int num: nums2){
            if(mp.find(num)!=mp.end()) st.insert(num);
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};