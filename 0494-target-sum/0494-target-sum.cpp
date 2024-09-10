class Solution {
    int perfectSum(vector<int>& arr, int sum)
	{
	    int n = arr.size();
        vector<int> prev(sum+1,0), curr(sum+1,0);
        if(arr[0]==0) prev[0] =2; //If sum==0 and At index 0, its sum is 0
        else prev[0] = 1; //Same as above but size is not zero
        if(arr[0]!=0 && arr[0]<=sum) prev[arr[0]] = 1;
        for(int ind=1;ind<n;ind++){
            for(int s=0;s<=sum;s++){
                int notTake = prev[s];
                int take=0;
                if(arr[ind]<=s) take = prev[s-arr[ind]];
                curr[s] = (take+notTake);
            }
            prev = curr;
        }
        return prev[sum];
	}

    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += arr[i];
        if ((totalSum - d<0) || (totalSum-d)%2) 
            return false;
        int sum = totalSum / 2;
        return perfectSum(arr, (totalSum - d)/2);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};