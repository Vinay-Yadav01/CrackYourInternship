class Solution {
    bool fibonacciSeq(string S, vector<int> &ans, int index) {
        if (index == S.length()) {
            return ans.size() > 2;
        }
        long num = 0;
        for (int i = index; i < S.length(); i++) {
            num = num * 10 + S[i] - '0';
            if (num > INT_MAX || num < 0) return false;
            if (S[index] == '0' && i > index) return false; 
            if (ans.size() < 2 || num == ((long)ans.back() + (long)ans[ans.size()-2])) {
                ans.push_back(num);
                if(fibonacciSeq(S, ans, i + 1)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        fibonacciSeq(S, ans, 0);
        return ans;
    }
};