class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, count = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0) {
                counter = nums[i];
                count++;
            }
            else if(nums[i]==counter) count++;
            else count--;
        }
        return counter;
    }
};