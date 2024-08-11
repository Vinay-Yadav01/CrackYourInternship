class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) ans++;
            int rem = sum-k;
            if(mp.find(rem)!=mp.end()) ans+=mp[rem];
            mp[sum]++;
        }
        return ans;
    }
};