class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int cnt = 0;
        vector<int> sorted(n - 1, false);
        for (int j = 0; j < m; j++) {
            bool bad = false;
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                cnt++;
                continue;
            }
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] < strs[i + 1][j]) {
                    sorted[i] = true;
                }
            }
        }
        return cnt;
    }
};