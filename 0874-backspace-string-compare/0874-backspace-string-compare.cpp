class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for (auto i : s) {
            if (i == '#') {
                if (!st1.empty())
                    st1.pop();

            } else
                st1.push(i);
        }
        for (auto i : t) {
            if (i == '#') {
                if (!st2.empty())
                    st2.pop();
            } else
                st2.push(i);
        }
        if (st1 == st2)
            return true;

        return false;
    }
};