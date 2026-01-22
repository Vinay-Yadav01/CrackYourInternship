class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = -1;

            // Find the leftmost adjacent pair with minimum sum
            for (int i = 0; i < nums.size() - 1; ++i) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // Replace the pair with their sum
            vector<int> temp;
            for (int i = 0; i < nums.size(); ++i) {
                if (i == idx) {
                    temp.push_back(nums[i] + nums[i + 1]);
                    ++i; // skip the next one
                } else {
                    temp.push_back(nums[i]);
                }
            }

            nums = temp;
            ++operations;
        }

        return operations;
    }
};
