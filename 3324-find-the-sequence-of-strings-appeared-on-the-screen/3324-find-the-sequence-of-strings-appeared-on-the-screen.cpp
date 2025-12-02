class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string cur = "a";
        ans.push_back(cur);
        int n = target.size(), ind = 0;
        while (ind < n) {
            char c = target[ind];
            while (cur.back() != c) {
                cur.back() = (cur.back() - 'a' + 1) % 26 + 'a';
                ans.push_back(cur);
            }
            ind++;
            if (ind < n) {
                cur.push_back('a');
                ans.push_back(cur);
            }
        }

        return ans;
    }
};
