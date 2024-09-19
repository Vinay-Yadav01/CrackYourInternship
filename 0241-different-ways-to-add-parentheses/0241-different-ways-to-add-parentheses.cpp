class Solution {
    vector<int> solve(string &expression, int i, int j, vector<vector<vector<int>>> &dp) {
        if(dp[i][j].size()!=0) return dp[i][j];
        vector<int> result;
        for (int ind = i; ind <= j; ind++) {
            if (expression[ind] == '+' || expression[ind] == '-' ||
                expression[ind] == '*') {
                vector<int> left_ans = solve(expression, i, ind - 1, dp);
                vector<int> right_ans = solve(expression,ind + 1, j, dp);
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
        return dp[i][j] =  result;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        return solve(expression, 0, n-1,dp);
    }
};