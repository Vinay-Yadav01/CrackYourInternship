class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> lis;
        for (auto& env : envelopes) {
            int h = env[1];
            int ind = lower_bound(lis.begin(), lis.end(), h) - lis.begin();
            if (ind == lis.size())
                lis.push_back(h);
            else
                lis[ind] = h;
        }
        return lis.size();
    }
};
