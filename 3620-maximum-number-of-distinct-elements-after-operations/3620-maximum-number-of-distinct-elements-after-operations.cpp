class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array
        int nextAvailable = INT_MIN;   // Tracks the next available distinct value
        int distinctCount = 0;         // Count of distinct elements

        for (int num : nums) {
            int minValue = max(num - k, nextAvailable);
            if (minValue <= num + k) {
                nextAvailable = minValue + 1; // Move to the next available value
                distinctCount++;             // Increment distinct element count
            }
        }

        return distinctCount;
    }
};