class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& r : image) {
            reverse(r.begin(), r.end());
            for (int& bit : r)
                bit = !bit;
        }
        return image;
    }
};