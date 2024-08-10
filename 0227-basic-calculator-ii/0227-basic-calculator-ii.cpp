class Solution {
private:
    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        }
        if (op == '*' || op == '/') {
            return 2;
        }
        return 0;
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    int calculate(string s) {
        string postfix = "";
        stack<char> st;

        // Convert infix to postfix
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                // Handle multi-digit numbers
                while (i < s.size() && isdigit(s[i])) {
                    postfix += s[i];
                    i++;
                }
                postfix += ' '; // Add a space to separate numbers
                i--;            // Adjust for the for-loop increment
            } else if (isOperator(c)) {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    postfix += st.top();
                    postfix += ' ';
                    st.pop();
                }
                st.push(c);
            } else {
                continue; // Skip spaces
            }
        }

        while (!st.empty()) {
            postfix += st.top();
            postfix += ' ';
            st.pop();
        }

        // Evaluate postfix expression
        stack<int> ans;
        for (int i = 0; i < postfix.size(); i++) {
            char ch = postfix[i];
            if (isdigit(ch)) {
                int num = 0;
                while (i < postfix.size() && isdigit(postfix[i])) {
                    num = num * 10 + (postfix[i] - '0');
                    i++;
                }
                ans.push(num);
            } else if (isOperator(ch)) {
                int num2 = ans.top();
                ans.pop();
                int num1 = ans.top();
                ans.pop();
                if (ch == '+')
                    ans.push(num1 + num2);
                else if (ch == '-')
                    ans.push(num1 - num2);
                else if (ch == '*')
                    ans.push(num1 * num2);
                else if (ch == '/')
                    ans.push(num1 / num2);
            }
        }
        return ans.top();
    }
};
