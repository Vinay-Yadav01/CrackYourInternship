class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (char ch : word) {
            mp[ch]++;
        }
        vector<int> v;
        for (auto it : mp) {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        int count = 0;
        int charCount = 0;
        for (int c : v) {
            charCount++;
            if (charCount <= 8) {
                count += 1 * c;
            } else if (charCount <= 16) {
                count += 2 * c;
            } else if (charCount <= 24) {
                count += 3 * c;
            } else
                count += 4 * c;
        }
        return count;
    }
};