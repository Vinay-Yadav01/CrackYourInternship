class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && !isVowel(s[i]))
                i++;
            while (j >= 0 && !isVowel(s[j]))
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};