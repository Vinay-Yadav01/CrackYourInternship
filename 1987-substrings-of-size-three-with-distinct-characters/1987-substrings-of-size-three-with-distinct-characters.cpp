class Solution {
    bool check(unordered_map<char, int>& mp) {
        for (auto it : mp) {
            if (it.second > 1)
                return false;
        }
        return true;
    }

public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int i = 0;
        unordered_map<char, int> mp;
        while (i < 3) {
            mp[s[i]]++;
            i++;
        }
        int count = 0;
        if (check(mp))
            count++;
        while (i < n) {
            char prevChar = s[i - 3];
            mp[prevChar]--;
            if (mp[prevChar] == 0)
                mp.erase(mp[prevChar]);
            mp[s[i]]++;
            if (check(mp))
                count++;
            i++;
        }
        return count;
    }
};