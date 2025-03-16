class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for (auto it : derived) {
            XOR ^= it;
        }
        return (XOR== 0);
    }
};