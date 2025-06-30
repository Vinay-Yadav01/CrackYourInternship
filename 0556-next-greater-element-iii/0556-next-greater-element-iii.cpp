class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int sz = str.size();
        int ind = -1; // break point
        for (int i = sz - 2; i >= 0; i--) {
            if (str[i] < str[i + 1]) {
                ind = i;
                break;
            }
        }

        // If break point does not exist:
        if (ind == -1)
            return -1;

        for (int i = sz - 1; i > ind; i--) {
            if (str[i] > str[ind]) {
                swap(str[i], str[ind]);
                break;
            }
        }
        reverse(str.begin() + ind + 1, str.end());

        long long res = stoll(str);
        return res > INT_MAX ? -1 : (int)res;
    }
};