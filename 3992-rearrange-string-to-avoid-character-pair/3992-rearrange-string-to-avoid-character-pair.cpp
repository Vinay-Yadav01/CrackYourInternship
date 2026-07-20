class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        if (y > x)
            sort(s.rbegin(), s.rend());
        else
            sort(s.begin(), s.end());
        return s;
    }
};