class Solution {
public:
    int singleNumber(vector<int>& nums) {
         map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        int ans = -1;
        for (auto it : m) {
            if (it.second == 1) {
                ans = it.first;
                break;
            }
        }
        
        return ans;
    }
};