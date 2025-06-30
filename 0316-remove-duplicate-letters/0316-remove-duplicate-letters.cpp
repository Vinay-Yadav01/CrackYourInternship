class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastOcc(26, 0);
        for (int i = 0; i < n; i++) {
            lastOcc[s[i] - 'a'] = i;
        }
        stack<char> st;
        vector<bool> seen(26, 0);
        for (int i = 0; i < n; i++) {
            if (seen[s[i] - 'a'])
                continue;
            while (!st.empty() && st.top() > s[i] &&
                   i < lastOcc[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};