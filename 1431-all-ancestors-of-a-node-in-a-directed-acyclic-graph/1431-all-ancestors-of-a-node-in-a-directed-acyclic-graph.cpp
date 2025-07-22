class Solution {
    vector<int> topoSort(int n, vector<int> adj[], vector<int>& indegree) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (int nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return topo;
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], indegree(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> topo = topoSort(n, adj, indegree);
        vector<set<int>> ancestors(n);

        for (int u : topo) {
            for (int v : adj[u]) {
                ancestors[v].insert(u); // Direct ancestor
                for (int anc : ancestors[u]) {
                    ancestors[v].insert(anc); // All ancestors of u are also ancestors of v
                }
            }
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return ans;
    }
};
