class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        for (int i = 1; i < bound; i *= x) {
            for (int j = 1; j < bound; j *= y) {
                if (i + j <= bound)
                    res.insert(i + j);
                else
                    break;
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(res.begin(), res.end());
    }
};