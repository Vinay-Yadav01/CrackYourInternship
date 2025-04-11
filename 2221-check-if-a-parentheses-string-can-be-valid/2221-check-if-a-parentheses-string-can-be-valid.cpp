class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false;

        int n = s.size();
        int minOpen = 0, maxOpen = 0;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    minOpen++;
                    maxOpen++;
                } else {
                    minOpen--;
                    maxOpen--;
                }
            } else {
                // s[i] is unlocked → we can flip it as needed
                minOpen--;    // treat it as ')'
                maxOpen++;    // or treat it as '('
            }

            if (maxOpen < 0) return false;
            minOpen = max(minOpen, 0);
        }

        return minOpen == 0;
    }
};
