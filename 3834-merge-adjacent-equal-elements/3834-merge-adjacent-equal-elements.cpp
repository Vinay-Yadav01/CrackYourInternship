class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;

        for (long long x : nums) {
            ans.push_back(x);
            while (ans.size() >= 2 && ans.back() == ans[ans.size()-2]) {
                long long val = ans.back();
                ans.pop_back();
                ans.back() += val;  
            }
        }

        return ans;
    }
};
