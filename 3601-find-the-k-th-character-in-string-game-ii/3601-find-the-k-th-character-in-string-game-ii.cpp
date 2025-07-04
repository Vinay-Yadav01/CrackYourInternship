class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int countOp = 0;
        long long val = k;
        while (val > 1) {
            int jump = ceil(log2(val));
            val -= pow(2, jump - 1);
            if (operations[jump - 1])
                countOp++;
        }
        return 'a' + (countOp % 26);
    }
};