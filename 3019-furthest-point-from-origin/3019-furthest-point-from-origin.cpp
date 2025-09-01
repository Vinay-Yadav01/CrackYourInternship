class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos = 0, count = 0;
        for (char ch : moves) {
            if (ch == 'L')
                pos--;
            else if (ch == 'R')
                pos++;
            else
                count++;
        }
        if (pos > 0) {
            pos += count;
        } else
            pos -= count;
        return abs(pos);
    }
};