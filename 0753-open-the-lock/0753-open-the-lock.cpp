class Solution {
    vector<string> options(string& lock) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            string temp = lock;
            temp[i] = (temp[i] - '0' + 1) % 10 + '0';
            res.push_back(temp);
            temp = lock;
            temp[i] = (temp[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(temp);
        }
        return res;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> vis;
        for (string deadend : deadends) {
            vis[deadend] = true;
        }
        if (vis.find("0000") != vis.end())
            return -1;
        queue<pair<string, int>> q; //[locks, turn]
        q.push({"0000", 0});
        while (!q.empty()) {
            auto [lock, turn] = q.front();
            q.pop();
            if (lock == target)
                return turn;
            for (string nbr : options(lock)) {
                if (vis.find(nbr) == vis.end()) {
                    vis[nbr] = true;
                    q.push({nbr, turn + 1});
                }
            }
        }
        return -1;
    }
};