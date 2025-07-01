class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int total = 1; // the word itself is always a valid possibility
        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            int len = j - i;
            if (len >= 2) {
                total += (len - 1); // Each of these are possible shortenings
            }
            i = j;
        }

        return total;
    }
};
