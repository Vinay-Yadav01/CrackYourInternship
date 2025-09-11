class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

public:
    string sortVowels(string s) {
        string vowelString = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i]))
                vowelString.push_back(s[i]);
        }
        sort(vowelString.begin(), vowelString.end());
        int vowelInd = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                ans.push_back(vowelString[vowelInd++]);
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};