class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> prefix(n, 1), suffix(n, 1);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1])
                prefix[i] = prefix[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1])
                suffix[i] = suffix[i + 1] + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (prefix[i] > time && suffix[i] > time)
                ans.push_back(i);
        }
        return ans;
    }
};