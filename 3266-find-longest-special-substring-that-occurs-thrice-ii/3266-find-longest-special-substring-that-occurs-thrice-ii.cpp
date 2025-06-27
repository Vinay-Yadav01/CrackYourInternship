class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, unordered_map<int, int>> freq;
        int n = s.size();
        for (int i = 0; i < n;) {
            char ch = s[i];
            int j = i;

            while (j < n && s[j] == ch)
                j++;

            int len = j - i;
            // Count substrings of length 1 to len for this run
            for (int l = 1; l <= len; ++l)
                freq[ch][l] += (len - l + 1);

            i = j;
        }

        int maxLen = -1;
        for (auto& [ch, lengths] : freq) {
            for (auto& [len, count] : lengths) {
                if (count >= 3)
                    maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
