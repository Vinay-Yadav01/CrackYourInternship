class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> charToPos(26);
        for (int i = 0; i < 26; i++) {
            charToPos[i] = {i / 5, i % 5};
        }
        int currRow = 0, currCol = 0;
        string ans = "";
        for (char ch : target) {
            int ind = ch - 'a';
            int nextRow = charToPos[ind].first;
            int nextCol = charToPos[ind].second;
            if (currRow == charToPos[25].first &&
                currCol == charToPos[25].second && ch != 'z') {
                ans += 'U';
                currRow--;
            }
            while (currCol != nextCol) {
                if (currCol < nextCol) {
                    ans += 'R';
                    currCol++;
                } else {
                    ans += 'L';
                    currCol--;
                }
            }
            while (currRow != nextRow) {
                if (currRow < nextRow) {
                    ans += 'D';
                    currRow++;
                } else {
                    ans += 'U';
                    currRow--;
                }
            }
            ans += '!';
        }
        return ans;
    }
};