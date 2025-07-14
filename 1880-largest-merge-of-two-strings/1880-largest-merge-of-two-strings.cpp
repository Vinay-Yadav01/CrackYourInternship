class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1.compare(i, word1.size() - i, word2, j, word2.size() - j) > 0)
                res += word1[i++];
            else
                res += word2[j++];
        }
        return res + word1.substr(i) + word2.substr(j);
    }
};