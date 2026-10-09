class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        int res = 0;
        for (auto& [num, cnt] : mp)
            if (cnt == 1)
                res += num;

        return res;
    }
};