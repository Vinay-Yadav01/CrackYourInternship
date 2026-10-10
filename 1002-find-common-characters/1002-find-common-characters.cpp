class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, 0);
        for (char c : words[0]) 
            freq[c - 'a']++;
        

        for (int i = 1; i < words.size(); i++) {
            vector<int> freq1(26, 0);
            for (char c : words[i]) {
                freq1[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                freq[j] = min(freq[j], freq1[j]);
            }
        }
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                string s(1, i + 'a');
                result.push_back(s);
                freq[i]--;
            }
        }
        return result;
    }
};