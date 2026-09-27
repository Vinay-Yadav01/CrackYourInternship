class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                while (!st.empty() && st.top() != "(") {
                    temp += st.top();  // build string in correct order
                    st.pop();
                }
                st.pop();  // pop the '('
                reverse(temp.begin(), temp.end());
                st.push(temp);
            } else {
                st.push(string(1, c));  // correct char to string conversion
            }
        }

        // Collect final answer
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
