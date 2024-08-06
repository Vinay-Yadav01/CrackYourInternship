class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i]!=' ') {
                string temp;
                while ((s[i]!=' ') && i < n) {
                    temp += s[i];
                    i++;
                }
                st.push(temp);
            } else
                continue;
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty())
                ans += " ";
        }
        return ans;
    }
};