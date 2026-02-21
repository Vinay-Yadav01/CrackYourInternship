class Solution {
    unordered_set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    bool isPrimeBits(int num) {
        int bitCount = __builtin_popcount(num);
        return st.find(bitCount) != st.end();
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int num = left; num <= right; num++)
            if (isPrimeBits(num))
                count++;

        return count;
    }
};