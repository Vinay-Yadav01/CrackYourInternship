class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word = "";
        string res = "";
        while (ss >> word && k > 0) {
            res += (word + " ");
            k--;
        }
        res.pop_back();
        return res;
    }
};