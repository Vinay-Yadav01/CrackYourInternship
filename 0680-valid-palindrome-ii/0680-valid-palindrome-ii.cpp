class Solution {
public:
    bool isPalindrome(const string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                // Try skipping either the left or the right character
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};
