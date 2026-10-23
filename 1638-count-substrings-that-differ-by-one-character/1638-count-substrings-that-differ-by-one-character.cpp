class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        int totalCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mismatched = 0;
                for (int k = 0; i + k < n && j + k < m; k++) {
                    if (s[i + k] != t[j + k]) {
                        mismatched++;
                    }
                    if (mismatched > 1) {
                        break; 
                    }
                    if (mismatched == 1) {
                        totalCount++; 
                    }
                }
            }
        }
        return totalCount;
    }
};