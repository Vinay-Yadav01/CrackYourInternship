class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxOcc = 0;
        for(int num: nums){
            mp[num]++;
            maxOcc = max(maxOcc, mp[num]);
        }
        int count = 0;
        for(auto it: mp){
            if(it.second == maxOcc) count+=maxOcc;
        }
        return count;
    }
};