class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> charCount(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            vector<int> count(26, 0);
            for (char ch : words[i]) {
                count[ch - 'a'] = 1;
            }
            charCount[i] = count;
        }
        int pairCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (charCount[i] == charCount[j])
                    pairCount++;
            }
        }
        return pairCount;
    }
};