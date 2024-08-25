class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int counter=1;
        for(auto num: nums){
            if(num>counter) break;
            if(num==counter) counter++;
        }
        return counter;
    }
};