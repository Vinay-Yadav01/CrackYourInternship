class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> mp;
        int cr = 0, mx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                cr++;
            else {
                mp[{nums[i], nums[i - 1]}]++;
                mp[{nums[i - 1], nums[i]}]++;
            }
        }

        for (auto it : mp)
            mx = max(mx, it.second);

        return cr + mx;
    }
};