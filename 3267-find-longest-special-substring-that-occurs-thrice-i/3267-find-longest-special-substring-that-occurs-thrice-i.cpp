class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = i; j < n && s[i] == s[j]; j++) {
                str += s[j];
                mp[str]++;
            }
        }
        string longestString = "";
        int maxLength = 0;
        for (auto& [str, freq] : mp) {
            if (freq < 3)
                continue;
            if (str > longestString) {
                maxLength = max(maxLength, (int)(str.length()));
                longestString = str;
            }
        }
        cout << longestString;
        return maxLength ? maxLength : -1;
    }
};