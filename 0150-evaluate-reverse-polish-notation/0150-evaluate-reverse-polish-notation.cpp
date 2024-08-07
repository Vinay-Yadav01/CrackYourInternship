class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int eval;
                if (token == "+") {
                    eval = num1 + num2;
                } else if (token == "-") {
                    eval = num1 - num2;
                } else if (token == "*") {
                    eval = num1 * num2;
                } else { // token == "/"
                    eval = num1 / num2;
                }
                st.push(eval);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
