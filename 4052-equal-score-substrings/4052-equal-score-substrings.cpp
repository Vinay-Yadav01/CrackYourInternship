class Solution {
public:
    bool scoreBalance(string s) {
        int totalScore = 0;
        for (char ch : s)
            totalScore += ch - 'a' + 1;

        int leftScore = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            leftScore += s[i] - 'a' + 1;
            int rightScore = totalScore - leftScore;
            if (leftScore == rightScore) return true;
        }
        return false;
    }
};
