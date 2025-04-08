class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        if (uniqueElements.size() == nums.size()) {
            return 0;
        }

        int operations = 0;
        while (!nums.empty()) {
            // Remove up to the first 3 elements
            nums.erase(nums.begin(),
                       nums.begin() + min(3, static_cast<int>(nums.size())));
            operations++;

            // Check if the remaining elements are distinct
            unordered_set<int> currentSet(nums.begin(), nums.end());
            if (currentSet.size() == nums.size()) {
                break;
            }
        }

        return operations;
    }
};