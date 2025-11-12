class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        int n = pattern.size();
        vector<string> res;
        for (string word : words) {
            vector<char> mp1(26, '0'), mp2(26, '0');
            bool flag = true;
            for (int i = 0; i < n; i++) {
                char w = word[i], p = pattern[i];
                if (mp1[w - 'a'] == '0')
                    mp1[w - 'a'] = p;
                else if (mp1[w - 'a'] != p) {
                    flag = false;
                    break;
                }
                if (mp2[p - 'a'] == '0')
                    mp2[p - 'a'] = w;
                else if (mp2[p - 'a'] != w) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(word);
        }
        return res;
    }
};