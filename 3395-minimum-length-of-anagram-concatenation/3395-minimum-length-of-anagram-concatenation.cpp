class Solution {
    bool isPossible(string& s, int size) {
        int n = s.size();
        vector<int> firstFreq(26, 0);
        for (int i = 0; i < size; i++)
            firstFreq[s[i] - 'a']++;
        int i = size;
        while (i < n) {
            vector<int> currFreq(26, 0);
            for (int j = i; j < i + size; j++) {
                currFreq[s[j] - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                if (firstFreq[j] != currFreq[j])
                    return false;
            }
            i+=size;
        }
        return true;
    }

public:
    int minAnagramLength(string s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (n % i == 0 && isPossible(s, i))
                return i;
        }
        return n;
    }
};