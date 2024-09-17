class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        stringstream ss(s1 + " " + s2);
        string word;
        unordered_map<string, int> mp;
        while (getline(ss, word, ' ')) {
            mp[word]++;
        }
        for (auto it : mp) {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};