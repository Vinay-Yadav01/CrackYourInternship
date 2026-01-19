class Solution {
    bool isPossible(vector<vector<int>>& pref, int threshold, int len) {
        int m = pref.size(), n = pref[0].size();

        for (int i = 0; i + len - 1 < m; i++) {
            for (int j = 0; j + len - 1 < n; j++) {
                int r = i + len - 1;
                int c = j + len - 1;

                int sum = pref[r][c];
                if (i > 0)
                    sum -= pref[i - 1][c];
                if (j > 0)
                    sum -= pref[r][j - 1];
                if (i > 0 && j > 0)
                    sum += pref[i - 1][j - 1];

                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pref = mat;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    pref[i][j] += pref[i - 1][j];
                if (j > 0)
                    pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0)
                    pref[i][j] -= pref[i - 1][j - 1];
            }
        }

        int s = 1, e = min(m, n), ans = 0;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (isPossible(pref, threshold, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};