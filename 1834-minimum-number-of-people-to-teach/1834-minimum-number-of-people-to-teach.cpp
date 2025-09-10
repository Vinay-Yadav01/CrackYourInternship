class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_set<int> prob_users; // users which can't communicate with
                                       // atleast one of their friend
        for (auto f : friendships) {
            int u = f[0] - 1, v = f[1] - 1; // u,v => friends
            bool flag = false;
            for (auto x : languages[u]) {
                for (auto y : languages[v]) {
                    if (x == y) {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag) {
                prob_users.insert(u);
                prob_users.insert(v);
            }
        }
        unordered_map<int, int> lang_cnt;
        for (auto user : prob_users) {
            for (auto x : languages[user]) {
                lang_cnt[x]++;
            }
        }
        int mxknown = 0;
        for (auto& [lang, cnt] : lang_cnt) {
            mxknown = max(mxknown, cnt);
        }
        return prob_users.size() - mxknown;
    }
};