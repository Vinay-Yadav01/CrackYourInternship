class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it] = 1;
        }
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int cnt = 1;
            if (mp.find(x - 1) != mp.end())
                continue;
            while (mp.find(x + 1) != mp.end()) {
                x++;
                cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};