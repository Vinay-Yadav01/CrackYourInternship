class Solution {
public:
    typedef long long ll;
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        int count = 0;
        ll minNuksan = INT_MAX;
        for(ll num:nums){
            if((num^k) > num){
                count++;
               sum += num^k;
            }
            else{
                sum+=num;
            }
            minNuksan = min(minNuksan,abs(num-(num^k)));
        }
        return (count%2 == 0) ? sum : sum - minNuksan;
    }
};