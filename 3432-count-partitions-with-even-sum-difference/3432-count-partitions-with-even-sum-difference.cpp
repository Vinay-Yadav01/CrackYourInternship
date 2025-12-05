class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num; 
        }

        int leftSum = 0, count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) { 
            leftSum += nums[i];   
            int rightSum = totalSum - leftSum; 
            if ((leftSum % 2) == (rightSum % 2)) {
                count++;
            }
        }

        return count;
    }
};
