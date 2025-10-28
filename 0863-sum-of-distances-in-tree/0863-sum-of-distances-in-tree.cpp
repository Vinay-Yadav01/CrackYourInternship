class Solution {
    vector<vector<int>> adj;
    vector<int> count, ans;

    void dfs1(int node, int parent) {
        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs1(child, node);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }

    void dfs2(int node, int parent) {
        for (int child : adj[node]) {
            if (child == parent) continue;
            ans[child] = ans[node] - count[child] + (count.size() - count[child]);
            dfs2(child, node);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        count.assign(n, 1);
        ans.assign(n, 0);

        dfs1(0, -1);  
        dfs2(0, -1);  
        return ans;
    }
};
