class Solution {
    bool isAnagram(unordered_map<char, int>& pMap, string& str) {
        unordered_map<char, int> strMap;
        for (char ch : str) {
            strMap[ch]++;
        }
        return pMap == strMap;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        unordered_map<char, int> pMap;
        for (char ch : p) {
            pMap[ch]++;
        }
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            string str = s.substr(i, k);
            if (isAnagram(pMap, str))
                ans.push_back(i);
        }
        return ans;
    }
};