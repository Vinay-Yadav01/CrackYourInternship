class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq1(26, 0), freq2(26, 0);
        vector<int> last(26, -1), first(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                int ind = c - 'a';
                freq1[ind]++;
                last[ind] = i;
            } else {
                int ind = c - 'A';
                freq2[ind]++;
                if (first[ind] == -1)
                    first[ind] = i;
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += (freq1[i] > 0 && freq2[i] > 0 && last[i] < first[i]);

        return cnt;
    }
};