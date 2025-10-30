class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0, maxFlipped = 0;
        for (int i = 0; i < flips.size(); i++) {
            maxFlipped = max(maxFlipped, flips[i]);
            if (maxFlipped == i + 1) ans++;
        }
        return ans;
    }
};
