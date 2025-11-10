class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int ans = 10;
        int start = 9, curr = 9;
        while (n > 1) {
            curr *= start;
            start--;
            n--;
            ans += curr;
        }
        return ans;
    }
};