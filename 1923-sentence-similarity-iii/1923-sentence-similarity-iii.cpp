class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size()<sentence2.size()) swap(sentence1,sentence2);
        stringstream ss1(sentence1);
        string str1;
        vector<string> s1;
        while (ss1 >> str1) {
            s1.push_back(str1);
        }

        stringstream ss2(sentence2);
        string str2;
        vector<string> s2;
        while (ss2 >> str2) {
            s2.push_back(str2);
        }
        int i = 0, j = s1.size() - 1;
        int k = 0, l = s2.size() - 1;
        while (i < s1.size() && k < s2.size() && s1[i] == s2[k]) {
            i++;
            k++;
        }

        while (l >= k && s1[j] == s2[l]) {
            j--;
            l--;
        }
        return l < k;
    }
};