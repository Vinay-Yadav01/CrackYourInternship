class Solution {
    void trim_right(string& ans) {
        int j = ans.size() - 1;
        while (j >= 0 && ans[j] == ' ') {
            ans.pop_back();
            j--;
        }
    }

public:
    string decodeCiphertext(string encodedText, int rows) {
        int sz = encodedText.size();
        int cols = sz / rows;
        cout << cols << endl;
        vector<vector<char>> arr(rows, vector<char>(cols));
        int ind = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = encodedText[ind++];
            }
        }
        string ans = "";
        int col = 0;
        while (col < cols) {
            int i = 0, j = col;
            while (i < rows && j < cols) {
                // cout << i << " " << j << endl;
                ans += arr[i][j];
                i++;
                j++;
            }
            col++;
        }
        trim_right(ans);
        return ans;
    }
};