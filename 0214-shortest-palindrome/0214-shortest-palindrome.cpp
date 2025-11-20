class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + "#" + rev_s;
        int n = temp.length();
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j])
                j = lps[j - 1];
            if (temp[i] == temp[j])
                j++;
            lps[i] = j; 
        }

        int to_add = s.length() - lps.back();
        return rev_s.substr(0, to_add) + s;
    }
};