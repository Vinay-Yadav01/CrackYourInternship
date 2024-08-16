class Solution {
private:
    void bfs(int src, vector<int> adjLis[], vector<int>& vis) {
        vis[src] = 1;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adjLis[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLis[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLis[i].push_back(j);
                    adjLis[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                bfs(i, adjLis, vis);
            }
        }
        return ans;
    }
};