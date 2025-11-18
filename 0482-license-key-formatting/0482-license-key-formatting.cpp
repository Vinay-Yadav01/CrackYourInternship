class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int count = 0;

        // iterate backwards
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;

            char c = toupper(s[i]);
            res.push_back(c);
            count++;

            if (count == k) {
                res.push_back('-');
                count = 0;
            }
        }

        if (!res.empty() && res.back() == '-')
            res.pop_back();

        reverse(res.begin(), res.end());
        return res;
    }
};
