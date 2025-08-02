class Solution {
    long long nCr[31][31]; 
    void buildCombinations() {
        for (int n = 0; n <= 30; n++) {
            nCr[n][0] = nCr[n][n] = 1;
            for (int r = 1; r < n; r++) {
                nCr[n][r] = nCr[n-1][r-1] + nCr[n-1][r];
            }
        }
    }

public:
    string kthSmallestPath(vector<int>& destination, int k) {
        buildCombinations();
        int row = destination[0];
        int col = destination[1];
        string ans = "";

        while (row > 0 || col > 0) {
            if (col > 0) {
                long long countHFirst = nCr[row + col - 1][row];
                if (k <= countHFirst) {
                    ans.push_back('H');
                    col--;
                } else {
                    ans.push_back('V');
                    row--;
                    k -= countHFirst;
                }
            } else {
                ans.push_back('V');
                row--;
            }
        }
        return ans;
    }
};
