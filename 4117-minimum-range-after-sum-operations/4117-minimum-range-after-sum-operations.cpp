class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> temp = {a, b, c};
        sort(temp.begin(), temp.end());
        return min(temp[2], temp[0] + temp[1]) - temp[0];
    }
};