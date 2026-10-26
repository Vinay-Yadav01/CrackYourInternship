class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> countMap;
        for (char c : s) {
            countMap[c]++;
        }
        
        int freq = countMap.begin()->second;
        for (auto& pair : countMap) {
            if (pair.second != freq) {
                return false;
            }
        }
        return true;
    }
};