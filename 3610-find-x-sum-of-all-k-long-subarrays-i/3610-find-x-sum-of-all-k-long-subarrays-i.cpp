class cmp {
public:
    // Custom comparator for sorting by frequency and then by value in
    // descending order
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

class Solution {

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        // Iterate through each subarray of length k
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> freq;

            // Count frequency of each element in the current subarray
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }

            // Move the frequency map to a vector for sorting
            vector<pair<int, int>> freqVec(freq.begin(), freq.end());

            // Sort the elements by frequency, then by value in descending order
            sort(freqVec.begin(), freqVec.end(), cmp());

            // Calculate the X-Sum by taking the occurrences of the top x
            // frequent elements
            int xSum = 0, count = 0;
            for (auto& p : freqVec) {
                if (count >= x)
                    break;
                xSum += p.first *
                        p.second; // Multiply the element value by its frequency
                count++;
            }

            result.push_back(xSum);
        }
        return result;
    }
};