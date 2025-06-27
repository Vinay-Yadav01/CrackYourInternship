class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.size();
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        bool valid = true;
        int maxi = 0, start = 0;
        for (int end = 0; end < n; end++) {
            if (freq[s[end] - 'a'] > 0 && freq[s[end] - 'a'] < k) {
                valid = false;
                maxi = max(maxi,
                           longestSubstring(s.substr(start, end - start), k));
                start = end + 1;
            }
        }
        if (valid)
            return s.size();
        return max(maxi, longestSubstring(s.substr(start), k));
    }
};