class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        if (n == 0) return "";
        vector<int> lps(n, 0);
        // build LPS array
        for (int i = 1, len = 0; i < n; ) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else { lps[i] = 0; i++; }
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};
