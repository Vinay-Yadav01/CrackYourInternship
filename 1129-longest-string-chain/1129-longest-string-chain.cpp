class Solution {
    bool checkPossible(string& word1, string& word2) {
        if (word1.size() != word2.size() + 1)
            return false;
        int first = 0, second = 0;
        while (first < word1.size()) {
            if (second < word2.size() && word1[first] == word2[second]) {
                first++;
                second++;
            } else
                first++;
        }
        return first == word1.size() && second == word2.size();
    }

    class comp {
    public:
        bool operator()(string& s1, string& s2) {
            return s1.size() < s2.size();
        }
    };

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(words.begin(), words.end(), comp());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkPossible(words[i], words[j]))
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};