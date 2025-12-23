class Solution {
    int dfs(int id, vector<vector<int>>& adj, vector<int>& informTime) {
        int maxi = 0;
        for (int subOrd : adj[id]) {
            maxi = max(maxi, dfs(subOrd, adj, informTime));
        }
        return informTime[id] + maxi;
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1)
                continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(headID, adj, informTime);
    }
};