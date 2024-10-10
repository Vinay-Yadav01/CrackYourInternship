class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxi[i] = max(nums[i], maxi[i+1]);
        }
        int i=0, j=0, ans=0;
        while(j<n){
            while(i<j && nums[i]>maxi[j]) i++;
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};