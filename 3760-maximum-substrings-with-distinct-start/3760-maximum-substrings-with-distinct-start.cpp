class Solution {
public:
    int maxDistinct(string s) {
        vector<int> flag(26, 0);
        int count = 0;
        for (char ch : s) {
            if (flag[ch - 'a']++ == 0)
                count++;
        }
        return count;
    }
};