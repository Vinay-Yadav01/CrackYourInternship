class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        // Check relative order of L and R without '_'
        string s1, s2;
        for (char c : start) if (c != '_') s1 += c;
        for (char c : target) if (c != '_') s2 += c;
        if (s1 != s2) return false;

        // Check valid movement
        while (i < n && j < n) {
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
            if (i == n || j == n) break;

            if (start[i] != target[j]) return false;

            if (start[i] == 'L' && j > i) return false; // L can’t move right
            if (start[i] == 'R' && j < i) return false; // R can’t move left

            i++; j++;
        }

        return true;
    }
};
