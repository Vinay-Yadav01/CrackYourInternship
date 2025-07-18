class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vector<int> vis(n, -1);
        vis[0] = 0;

        while (!q.empty()) {
            int ind = q.front();
            q.pop();

            if (ind == n - 1)
                return vis[ind];

            // Jump to ind + 1
            if (ind + 1 < n && vis[ind + 1] == -1) {
                q.push(ind + 1);
                vis[ind + 1] = vis[ind] + 1;
            }

            // Jump to ind - 1
            if (ind - 1 >= 0 && vis[ind - 1] == -1) {
                q.push(ind - 1);
                vis[ind - 1] = vis[ind] + 1;
            }

            // Jump to same-value indices
            for (int newInd : mp[arr[ind]]) {
                if (vis[newInd] == -1) {
                    q.push(newInd);
                    vis[newInd] = vis[ind] + 1;
                }
            }

            // Avoid revisiting same value jumps again
            mp[arr[ind]].clear();
        }

        return -1;
    }
};
