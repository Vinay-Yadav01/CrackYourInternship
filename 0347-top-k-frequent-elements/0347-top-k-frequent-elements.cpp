class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp; //Num and its occ.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(pq.size()<k) pq.push({i.second, i.first});
            else {
               if(pq.top().first<i.second){
                pq.pop();
                pq.push({i.second, i.first});
               }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};