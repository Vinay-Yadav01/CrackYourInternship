class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ',')
                continue;
            if (expression[i] != ')')
                st.push(expression[i]);
            else {
                bool hasTrue = false, hasFalse = false;
                while (st.top() != '(') {
                    if (st.top() == 't')
                        hasTrue = true;
                    else
                        hasFalse = true;
                    st.pop();
                }
                st.pop(); //Popped '('
                char operand = st.top();
                st.pop();
                char ch;
                if (operand == '&') {
                    ch = (hasFalse) ? 'f' : 't';
                } else if (operand == '|') {
                    ch = (hasTrue) ? 't' : 'f';
                } else {
                    ch = (hasFalse) ? 't'
                                    : 'f'; // Means it has false so invert it
                }
                st.push(ch);
            }
        }
        if (st.top() == 't')
            return true;
        else
            return false;
    }
};