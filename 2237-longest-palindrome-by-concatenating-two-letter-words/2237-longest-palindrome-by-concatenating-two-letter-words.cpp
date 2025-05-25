class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        for (auto word : words) {
            mp[word]++;
        }

        bool iscenterUsed = false;
        int res = 0;

        for (auto word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (rev != word) { // ab.....ba
                if (mp[word] > 0 && mp[rev] > 0) {
                    mp[word]--;
                    mp[rev]--;
                    res += 4;
                }
            } else { // else if word is same  abcc......ccba
                if (mp[word] >= 2) {
                    res += 4;
                    mp[word] -= 2;
                } else if (mp[word] == 1 &&
                           iscenterUsed == false) { // abccddccba center can be
                                                    // only used once
                    res += 2;
                    iscenterUsed = true;
                }
            }
        }
        return res;
    }
};