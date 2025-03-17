class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream s(sentence);
        string word;
        s >> word;
        char firstStringFirstChar = word[0];
        char prevStringLastChar = word.back();
        while (s >> word) {
            char currWordFirstChar = word[0];
            if (currWordFirstChar != prevStringLastChar)
                return false;
            prevStringLastChar = word.back();
        }
        return prevStringLastChar == firstStringFirstChar;
    }
};