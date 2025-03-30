class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        int size = 0, maxLast = 0;
        vector<int> last(26, 0);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            maxLast = max(maxLast, last[s[i] - 'a']);
            size++;
            if (i == maxLast) {
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};