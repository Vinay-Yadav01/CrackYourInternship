class Solution {
    bool check(string w1, string w2) {
        reverse(w1.begin(), w1.end());
        return w1 == w2;
    }

public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (check(words[i], words[j]))
                    res++;

        return res;
    }
};