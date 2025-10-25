class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans;
        ans.push_back(pref[0]);
        for (int i = 1; i < n; i++) {
            int prevXOR = pref[i - 1];
            int curXOR = pref[i];
            int num = prevXOR ^ curXOR;
            ans.push_back(num);
        }
        return ans;
    }
};