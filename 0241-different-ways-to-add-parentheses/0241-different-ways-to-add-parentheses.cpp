class Solution {
    vector<int> solve(string expression) {
        vector<int> result;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*') {
                vector<int> left_ans = solve(expression.substr(0, i));
                vector<int> right_ans = solve(expression.substr(i + 1));
                for (auto& left : left_ans) {
                    for (auto& right : right_ans) {
                        if (expression[i] == '+') {
                            result.push_back(left + right);
                        } else if (expression[i] == '-') {
                            result.push_back(left - right);
                        } else {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }
        if (result.size() == 0)
            result.push_back(stoi(expression));
        return result;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};