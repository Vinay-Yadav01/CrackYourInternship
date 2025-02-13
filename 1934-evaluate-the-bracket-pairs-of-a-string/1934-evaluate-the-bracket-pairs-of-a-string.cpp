class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto str : knowledge) {
            mp[str[0]] = str[1];
        }
        string ans = "";
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                i++;
                string key = "";
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else
                    ans += '?';
            } else
                ans += s[i];
            i++;
        }
        return ans;
    }
};