class Solution {
public:
    int partitionString(string s) {
        vector<int> ch(26, 0);
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            while (i < n && ch[s[i] - 'a'] == 0) {
                ch[s[i] - 'a']++;
                i++;
            }
            i--;  // Adjust index after exiting the while loop
            count++;
            fill(ch.begin(), ch.end(), 0);  // Reset vector to zeros
        }
        return count;
    }
};