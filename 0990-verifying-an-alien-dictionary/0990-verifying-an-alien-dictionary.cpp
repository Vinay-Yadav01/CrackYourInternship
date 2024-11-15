class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.length(); i++) {
            mp[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len1 = w1.length();
            int len2 = w2.length();
            int len = min(len1, len2);
            // Check if w1 is longer than w2 but they are identical up to the
            // length of w2
            if (len1 > len2 && w1.substr(0, len) == w2.substr(0, len)) {
                return false;
            }

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (mp[w1[j]] > mp[w2[j]]) {
                        return false;
                    }
                    break;  // No need to check further once a difference is found
                }
            }
        }
        return true;
    }
};