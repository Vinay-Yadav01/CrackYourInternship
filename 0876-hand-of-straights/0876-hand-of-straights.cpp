class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> freq;
        for (int i : hand)
            freq[i]++;
        for (auto it : freq){
            if (freq[it.first] > 0) {
                for (int i = groupSize - 1; i >= 0; --i) {
                    if (freq[it.first + i] < freq[it.first]) {
                        return false;
                    }
                    freq[it.first + i] -= freq[it.first];
                }
            }
        }
        return true;
    }
};