class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> val(26, 0);
        for (int i = 0; i < 26; i++) {
            val[i] = i + 1;
        }
        for (int i = 0; i < chars.size(); i++) {
            int ind = chars[i] - 'a';
            val[ind] = vals[i];
        }
        int maxSum = 0, currSum = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            currSum += val[s[i] - 'a'];
            maxSum = max(maxSum, currSum);
            currSum = max(currSum, 0);
        }
        return maxSum;
    }
};