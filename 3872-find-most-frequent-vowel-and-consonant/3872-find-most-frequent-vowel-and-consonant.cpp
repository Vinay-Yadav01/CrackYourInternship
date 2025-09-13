class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    int maxFreqSum(string s) {
        vector<int> charCount(26, 0);
        for (char ch : s) {
            charCount[ch - 'a']++;
        }
        int maxVowelCount = 0, maxConsCount = 0;
        for (int i = 0; i < 26; i++) {
            if (isVowel('a' + i))
                maxVowelCount = max(maxVowelCount, charCount[i]);
            else
                maxConsCount = max(maxConsCount, charCount[i]);
        }
        return maxVowelCount + maxConsCount;
    }
};