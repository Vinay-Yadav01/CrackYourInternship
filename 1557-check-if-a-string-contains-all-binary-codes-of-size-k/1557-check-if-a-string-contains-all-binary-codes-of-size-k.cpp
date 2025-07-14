class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size(), i = 0;
        unordered_set<string> st;
        int total = (1 << k);
        while (i <= n - k) {
            string temp = s.substr(i, k);
            st.insert(temp);
            if (st.size() == total)
                return true;
            i++;
        }
        return st.size() == total;
    }
};