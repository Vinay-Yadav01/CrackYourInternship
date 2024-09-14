class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = INT_MIN;
        for(auto num: nums){
            maxElement = max(maxElement, num);
        }
        int count=0, maxi=0;
        for(auto num : nums){
            if(num==maxElement){
                count++;
                maxi = max(maxi, count);
            }
            else{
                count=0;
            }
        }
        return maxi;
    }
};