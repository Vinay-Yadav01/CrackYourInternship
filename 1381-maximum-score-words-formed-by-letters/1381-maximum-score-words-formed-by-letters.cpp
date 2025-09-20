class Solution {
    void solve(int index, unordered_map<char, int> letterCounter, int currScore,
               int& totalScore, vector<string>& words, vector<int>& score) {
        totalScore = max(totalScore, currScore);
        if (index == words.size())
            return;

        for (int i = index; i < words.size(); ++i) {
            unordered_map<char, int> tmpCounter = letterCounter;
            string word = words[i];
            int wordScore = 0;
            bool isValid = true;

            for (char ch : word) {
                if (tmpCounter[ch] > 0) {
                    tmpCounter[ch]--;
                    wordScore += score[ch - 'a'];
                } else {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                solve(i + 1, tmpCounter, currScore + wordScore, totalScore,
                      words, score);
            }
        }
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        unordered_map<char, int> lettersCounter;
        for (char letter : letters) {
            lettersCounter[letter]++;
        }

        int totalScore = 0;

        solve(0, lettersCounter, 0, totalScore, words, score);
        return totalScore;
    }
};