class Solution {
    int prefixCommon(vector<int>& count1, vector<int>& count2, int n) {
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            cnt += min(count1[i], count2[i]);
        }
        return cnt;
    }

public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count1(n + 1, 0), count2(n + 1, 0);
        vector<int> C(n);
        for (int i = 0; i < n; i++) {
            count1[A[i]]++;
            count2[B[i]]++;
            C[i] = prefixCommon(count1, count2, n);
        }
        return C;
    }
};