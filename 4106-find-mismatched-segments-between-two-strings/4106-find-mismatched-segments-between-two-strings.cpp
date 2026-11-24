class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> res;
        int n = s1.size();
        int ind = 0;
        while (ind < n) {
            while (ind < n && s1[ind] == s2[ind])
                ind++;

            string str1 = "", str2 = "";
            bool flag = false;
            while (ind < n && s1[ind] != s2[ind]) {
                str1 += s1[ind];
                str2 += s2[ind];
                ind++;
                flag = true;
            }
            if (flag)
                res.push_back({str1, str2});
        }
        return res;
    }
};