class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        int n = friends.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(id);
        vis[id] = 1;

        for (int l = 0; l < level; ++l) {
            int sz = q.size();
            if (sz == 0)
                break;
            while (sz--) {
                int cur = q.front();
                q.pop();
                for (int nbr : friends[cur]) {
                    if (!vis[nbr]) {
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
        }

        unordered_map<string, int> freq;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (string& vid : watchedVideos[cur])
                ++freq[vid];
        }

        vector<pair<string, int>> items;
        for (auto& p : freq)
            items.emplace_back(p.first, p.second);

        sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second; // smaller frequency first
        });

        vector<string> ans;
        ans.reserve(items.size());
        for (auto& p : items)
            ans.push_back(p.first);
        return ans;
    }
};
