class Solution {
    bool check(int num) {
        vector<int> count(10, 0);
        while (num) {
            int digit = num % 10;
            num /= 10;
            count[digit]++;
        }
        if (count[3] > 0 || count[4] > 0 || count[7] > 0) {
            return false;
        }
        if (count[2] > 0 || count[5] > 0 || count[6] > 0 || count[9] > 0) {
            return true;
        }
        return false;
    }

public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                ans++;
            }
        }
        return ans;
    }
};