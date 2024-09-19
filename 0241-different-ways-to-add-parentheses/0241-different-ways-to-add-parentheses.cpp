class Solution {
    vector<int> solve(string &expression, int i, int j) {
        vector<int> result;
        for (int ind = i; ind <= j; ind++) {
            if (expression[ind] == '+' || expression[ind] == '-' ||
                expression[ind] == '*') {
                vector<int> left_ans = solve(expression, i, ind - 1);
                vector<int> right_ans = solve(expression,ind + 1, j);
                for (auto& left : left_ans) {
                    for (auto& right : right_ans) {
                        if (expression[ind] == '+') {
                            result.push_back(left + right);
                        } else if (expression[ind] == '-') {
                            result.push_back(left - right);
                        } else {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }
        if (result.size() == 0)
            result.push_back(stoi(expression.substr(i,j-i+1)));
        return result;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return solve(expression, 0, n-1);
    }
};