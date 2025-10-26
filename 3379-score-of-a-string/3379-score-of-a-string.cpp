class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            ans += abs(s[i + 1] - s[i]);
        }
        return ans;
    }
};