class Solution {
public:
    int minRotations(string s) {
        int from = 0;
        int rotations = 0;
        for (char c : s) {
            int to = c - '0';
            rotations += min(abs(from - to), 10 - abs(from - to));
            from = to;
        }
        return rotations;
    }
};