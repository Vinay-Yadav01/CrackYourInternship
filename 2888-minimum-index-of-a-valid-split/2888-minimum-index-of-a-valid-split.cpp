class Solution {
    int mooreVoting(vector<int>& nums) {
        int n = nums.size();
        int maxElement = nums[0];
        int freq = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == maxElement) {
                freq++;
            } else {
                freq--;
                if (freq == 0) {
                    maxElement = nums[i];
                    freq = 1;
                }
            }
        }
        return maxElement;
    }

public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominantElement = mooreVoting(nums);
        int freq = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominantElement)
                freq++;
        }
        int leftOcc = 0, rightOcc = freq;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominantElement) {
                leftOcc++;
                rightOcc--;
            }
            if (leftOcc > (i + 1) / 2 && rightOcc > (n - 1 - i) / 2)
                return i;
        }
        return -1;
    }
};