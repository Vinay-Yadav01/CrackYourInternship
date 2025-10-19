class Solution {
    string addOperation(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        }
        return s;
    }

    string rotateOperation(string s, int b) {
        rotate(s.begin(), s.begin() + b, s.end());
        return s;
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;
        string ans = s;

        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            ans = min(ans, cur);

            string added = addOperation(cur, a);
            if (vis.find(added) == vis.end()) {
                vis.insert(added);
                q.push(added);
            }

            string rotated = rotateOperation(cur, b);
            if (vis.find(rotated) == vis.end()) {
                vis.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};
