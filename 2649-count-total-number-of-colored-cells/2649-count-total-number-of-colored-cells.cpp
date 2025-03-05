class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1LL * pow(n, 2) + 1LL * pow(n - 1, 2);
        return ans;
    }
};