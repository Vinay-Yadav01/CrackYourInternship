class Solution {
    string emailMask(string& s) {
        string ans;
        bool flag = false;
        int i = 0, n = s.size();
        while (i < n) {
            if (i == 0 || flag) {
                ans += tolower(s[i]);
            } else if (s[i] == '@') {
                ans += s[i];
                flag = true;
            } else {
                while (i + 1 < n && s[i + 1] != '@')
                    i++;
                ans += "*****";
                ans += tolower(s[i]);
            }
            i++;
        }
        return ans;
    }

    string phoneMask(string& s) {
        string temp, ans;
        int i = 0, n = s.size();
        while (i < n) {
            if (isdigit(s[i]))
                temp += s[i];
            i++;
        }
        int sz = temp.size();
        if (sz == 10)
            ans += "***-***-";
        else if (sz == 11)
            ans += "+*-***-***-";
        else if (sz == 12)
            ans += "+**-***-***-";
        else
            ans += "+***-***-***-";
        ans += temp.substr(sz - 4);
        return ans;
    }

public:
    string maskPII(string s) {
        bool isEmail = s.find("@") != string::npos;
        return isEmail ? emailMask(s) : phoneMask(s);
    }
};