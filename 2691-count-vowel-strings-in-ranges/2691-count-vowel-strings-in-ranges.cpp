class Solution {
    bool startsAndEndsWithVowel(const string& word) {
        char first = word.front();
        char last = word.back();
        return isVowel(first) && isVowel(last);
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> count(n + 1, 0); // prefix sum

        for (int i = 1; i <= n; ++i) {
            count[i] = count[i - 1] + (startsAndEndsWithVowel(words[i - 1]) ? 1 : 0);
        }

        vector<int> ans;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            ans.push_back(count[r + 1] - count[l]);
        }

        return ans;
    }
};
