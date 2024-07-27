class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(auto i:nums){
            if(mp.find(i)==mp.end()) mp[i] = 1;
            else mp[i]++;
        }
        vector<int> ans;
        for(auto i:mp){
            if(i.second>=2) ans.push_back(i.first);
        }
        return ans;
    }
};