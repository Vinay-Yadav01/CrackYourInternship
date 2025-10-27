class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> mp1, mp2;
        for (auto ch : s) {
            mp1[ch]++;
        }
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            mp1[s[i]]--;
            if (mp1[s[i]] == 0)
                mp1.erase(s[i]);
            mp2[s[i]]++;
            if (mp2.size() == mp1.size())
                count++;
        }
        return count;
    }
};