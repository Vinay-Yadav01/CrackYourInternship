class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int ind = 0, leftVal = 0, rightVal = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I')
                ans[ind++] = leftVal++;
            else
                ans[ind++] = rightVal--;
        }
        if (s.back() == 'I')
            ans[ind] = leftVal;
        else
            ans[ind] = rightVal;
        return ans;
    }
};