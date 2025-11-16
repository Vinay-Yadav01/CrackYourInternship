class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int cnt = 0, i = 0;
        const int MOD = 1e9 + 7;
        while (i < n) {
            while (i < n && s[i] == '0')
                i++;
            if (i == n)
                break;
            int j = i + 1;
            while (j < n && s[j] == '1')
                j++;
            cnt += (((long long)(j - i) * (j - i + 1)) / 2) % MOD;
            i = j;
        }
        return cnt;
    }
};