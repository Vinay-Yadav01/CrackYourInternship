class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int val = 0;
        for (int num : nums) {
            val = (val * 2 + num) % 5;
            if (val == 0)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};