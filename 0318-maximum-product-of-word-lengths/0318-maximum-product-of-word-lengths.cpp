class Solution {
    bool haveCommon(vector<bool>& count1, vector<bool>& count2) {
        for (int i = 0; i < 26; i++) {
            if (count1[i] > 0 && count2[i] > 0 && count1[i] == count2[i])
                return true;
        }
        return false;
    }

public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> count(n, vector<bool>(26, false));
        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                count[i][ch - 'a'] = true;
            }
        }
        int maxLength = 0;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!haveCommon(count[i], count[j])) {
                    maxLength = max(maxLength, (int)(words[i].length() *
                                                     words[j].length()));
                }
            }
        }
        return maxLength;
    }
};