class Solution {
    string f(string str) {
        string ans = "";
        for (char ch : str) {
            ans += (ch - 'a' + 1) % 26 + 'a';
        }
        return ans;
    }

public:
    char kthCharacter(int k) {
        string str = "a";
        while (str.size() <= k) {
            string next_str = f(str);
            str += next_str;
        }
        cout<<str;
        return str[k-1];
    }
};