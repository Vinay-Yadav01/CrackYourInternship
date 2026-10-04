class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m;
        string one = "qwertyuiopQWERTYUIOP";
        string two = "asdfghjklASDFGHJKL";
        string three = "zxcvbnmZXCVBNM";
        for (char& ch : one)
            m[ch] = 1;
        for (char& ch : two)
            m[ch] = 2;
        for (char& ch : three)
            m[ch] = 3;

        vector<string> v;
        for (string& str : words) {
            int ind = m[str[0]];
            bool flag = true;
            for (char& ch : str) {
                if (m[ch] != ind) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                v.push_back(str);
        }
        return v;
    }
};