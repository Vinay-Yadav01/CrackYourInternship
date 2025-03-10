class Solution {
    bool isVowel(char& ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }

    long long countAtLeastK(string word, int k) {
        int n = word.size();
        unordered_map<char, int> vowels;
        int consonants = 0;
        int l = 0, r = 0;
        long long count = 0;
        while (r < n) {
            char ch = word[r];
            if (isVowel(ch)) {
                vowels[ch]++;
            } else {
                consonants++;
            }
            while (vowels.size() == 5 && consonants >= k) {
                count += (n - r);
                char temp = word[l];
                if (isVowel(temp)) {
                    vowels[temp]--;
                    if (vowels[temp] == 0)
                        vowels.erase(temp);
                } 
                else consonants--;
                l++;
            }
            r++;
        }
        return count;
    }


public:
    long long countOfSubstrings(string word, int k) {
        return countAtLeastK(word, k) - countAtLeastK(word, k + 1);
    }
};