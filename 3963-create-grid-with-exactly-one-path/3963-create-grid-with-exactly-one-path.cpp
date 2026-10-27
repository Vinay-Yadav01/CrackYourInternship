class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m);
        for (int i = 0; i < m; i++) {
            string str(n, '#');
            for (int j = 0; j < n; j++)
                if (i == 0 || j == n - 1)
                    str[j] = '.';
            res[i] = str;
        }
        return res;
    }
};