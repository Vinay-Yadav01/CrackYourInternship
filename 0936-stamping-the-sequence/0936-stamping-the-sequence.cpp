class Solution {
    bool canStamp(string &stamp, string &target, int pos, int &cnt) {
        cnt = 0;
        for (int i = 0; i < stamp.size(); i++) {
            if (target[pos + i] == '?') continue;
            if (target[pos + i] != stamp[i]) return false;
            cnt++;
        }
        return cnt > 0;
    }

    void doStamp(string &target, int pos, int n) {
        for (int i = 0; i < n; i++) {
            target[pos + i] = '?';
        }
    }

public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.size(), m = target.size();
        vector<bool> visited(m, false);
        vector<int> ans;
        int replaced = 0;

        while (replaced < m) {
            bool progress = false;

            for (int i = 0; i <= m - n; i++) {
                if (visited[i]) continue;

                int cnt = 0;
                if (canStamp(stamp, target, i, cnt)) {
                    visited[i] = true;
                    doStamp(target, i, n);
                    replaced += cnt;   
                    ans.push_back(i);
                    progress = true;
                }
            }

            if (!progress) return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
