class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int oneCount = 0;
        for(auto num: nums) oneCount+=num; //For every one it will increase
        nums.insert(nums.end(), nums.begin(), nums.end());
        int minZero = 0;
        for(int i=0;i<oneCount;i++){
            if(nums[i]==0) minZero++;
        }
        int i=0, j=oneCount-1;
        int n = nums.size();
        int zeroCount = minZero;
        while(i<n){
            //Check element at i and increment
            if(nums[i]==0) zeroCount--;
            i++;
            //Increase j and check it
            j++;
            if(nums[j%n]==0) zeroCount++;
            minZero = min(minZero, zeroCount);
        }
        return minZero;
    }
};