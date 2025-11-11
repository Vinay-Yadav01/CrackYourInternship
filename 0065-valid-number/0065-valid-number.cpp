class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ')
            i++;

        while (n > i && s[n - 1] == ' ')
            n--;

        bool num = false, dot = false, exp = false;

        while (i < n) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = true;
            } else if (ch == '+' || ch == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            } else if (ch == '.') {
                if (dot || exp)
                    return false;
                dot = true;
            } else if (ch == 'e' || ch == 'E') {
                if (exp || !num)
                    return false;
                exp = true;
                num = false;
            } else {
                return false;
            }
            i++;
        }

        return num;
    }
};
