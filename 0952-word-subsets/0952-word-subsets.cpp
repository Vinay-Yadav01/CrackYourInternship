class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);

        // Step 1: Compute maximum required frequency of each letter in words2
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
                maxFreq[ch - 'a'] = max(maxFreq[ch - 'a'], freq[ch - 'a']);
            }
        }

        vector<string> ans;

        // Step 2: Check each word in words1
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
