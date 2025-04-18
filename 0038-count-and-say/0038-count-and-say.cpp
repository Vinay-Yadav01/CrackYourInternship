class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string say = countAndSay(n - 1);
        string ans = "";
        int size = say.size();
        int i = 0;
        while (i < size) {
            int cnt = 1;
            char ch = say[i];
            i++;
            while (i < size && say[i] == ch) {
                cnt++;
                i++;
            }
            ans += to_string(cnt) + ch;
        }
        return ans;
    }
};