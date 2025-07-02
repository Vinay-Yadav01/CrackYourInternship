class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (auto shift : shifts) {
            prefix[shift[0]] += (shift[2] == 1) ? 1 : -1;
            prefix[shift[1] + 1] -= (shift[2] == 1) ? 1 : -1;
        }
        for (int i = 0; i < n; i++) {
            if (prefix[i] > 0)
                s[i] = (s[i] - 'a' + (prefix[i]) % 26) % 26 + 'a';
            else 
                s[i] = (s[i] - 'a' + (prefix[i]) % 26 + 26) % 26 + 'a';
            prefix[i + 1] += prefix[i];
        }
        return s;
    }
};