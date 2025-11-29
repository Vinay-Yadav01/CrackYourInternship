class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length(), len = 0;
        vector<int> arr(26, -1);
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if (arr[idx] != -1 && i - arr[idx] + 1 >= 4) {
                len++;
                arr.assign(26, -1);
            } else {
                if (arr[idx] == -1) {
                    arr[idx] = i;
                }
            }
        }
        return len;
    }
};