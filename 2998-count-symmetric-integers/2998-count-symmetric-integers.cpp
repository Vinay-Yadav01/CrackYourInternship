class Solution {
    int checkSymmetricity(int n) {
        string num = to_string(n);
        int i = 0, j = num.size() - 1;
        int leftSum = 0, rightSum = 0;
        while (i < j) {
            leftSum += num[i++]-'0';
            rightSum += num[j--]-'0';
        }
        return leftSum == rightSum;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            int noOfDigit = log10(i) + 1;
            if (noOfDigit % 2)
                continue;
            else if (checkSymmetricity(i))
                cnt++;
        }
        return cnt;
    }
};