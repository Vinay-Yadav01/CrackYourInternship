class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<int> ans;
        for (auto [it, val] : mp) {
            if (val > 1 || mp.find(it - 1) != mp.end() ||
                mp.find(it + 1) != mp.end())
                continue;
            ans.push_back(it);
        }
        return ans;
    }
};