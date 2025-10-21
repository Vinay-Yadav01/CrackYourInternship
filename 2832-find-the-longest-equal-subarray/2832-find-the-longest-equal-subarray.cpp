class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0, maxLen = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
            maxFreq = max(maxFreq, freq[nums[j]]);
            if (j - i + 1 - maxFreq > k) {
                freq[nums[i]]--;
                i++;
            }
        }
        return maxFreq;
    }
};