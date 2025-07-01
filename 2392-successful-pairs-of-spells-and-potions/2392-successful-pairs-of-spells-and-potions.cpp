class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            long long req = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), req);
            if (it != potions.end()) {
                int ind = it - potions.begin();
                ans[i] = m - ind;
            }
        }
        return ans;
    }
};