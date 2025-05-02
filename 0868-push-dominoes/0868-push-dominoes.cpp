class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<char> dom(dominoes.begin(), dominoes.end());
        queue<pair<int, char>> q;
        int n = dom.size();
        for (int i = 0; i < n; i++) {
            if (dom[i] != '.')
                q.push({i, dom[i]});
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int i = node.first;
            char ch = node.second;
            if (ch == 'L') {
                if (i > 0 && dom[i - 1] == '.') {
                    dom[i - 1] = 'L';
                    q.push({i - 1, 'L'});
                }
            } else { // R
                if (i + 1 < n && dom[i + 1] == '.') {
                    if (i + 2 < n && dom[i + 2] == 'L')
                        q.pop();
                    else {
                        dom[i + 1] = 'R';
                        q.push({i + 1, 'R'});
                    }
                }
            }
        }
        string ans(dom.begin(), dom.end());
        return ans;
    }
};