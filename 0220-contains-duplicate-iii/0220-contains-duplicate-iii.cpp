class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> window;

        for (int i = 0; i < nums.size(); i++) {
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            // Check if this value is within valueDiff range
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff)
                return true;

            window.insert(nums[i]);

            // Maintain window size
            if (i >= indexDiff)
                window.erase(nums[i - indexDiff]);
        }

        return false;
    }
};
