class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> count(26, 0);
        for (auto ch : allowed) {
            count[ch - 'a'] = 1;
        }
        int ans = 0;
        for (auto word : words) {
            bool flag = false;
            for (auto ch : word) {
                if (count[ch - 'a'] != 1) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                ans++;
        }
        return ans;
    }
};