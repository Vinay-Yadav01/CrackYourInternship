class Solution {
public:
    int minimumChairs(string s) {
        int count = 0, maxCount = 0;
        for (char c : s) {
            if (c == 'E')
                count++;
            else
                count--;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};