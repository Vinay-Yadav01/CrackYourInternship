class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> encoding = {
            ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
            "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
            "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
            "...-", ".--",  "-..-", "-.--", "--.."};
        unordered_map<string, bool> mp;
        int count = 0;
        for (auto word : words) {
            string temp = "";
            for (auto ch : word) {
                int index = ch - 'a';
                temp += encoding[index];
            }
            cout << temp << endl;
            if (mp.find(temp) == mp.end())
                count++;
            mp[temp] = true;
        }
        return count;
    }
};