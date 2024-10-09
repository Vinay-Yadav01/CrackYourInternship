class Solution {
    bool dfs(int start, vector<int>& vis, vector<int>& pathVis,
             vector<int>& check, vector<vector<int>>& graph) {
        vis[start] = 1;
        pathVis[start] = 1;
        for (auto it : graph[start]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, check, graph) == true)
                    return true;
            } else if (pathVis[it] == 1)
                return true;
        }
        check[start] = 1; // Means this node is NOT Connected to loop
        pathVis[start] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0); // 0-> Connected with loop
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathVis, check, graph);
            }
        }
        vector<int> safe;
        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safe.push_back(i);
        }
        return safe;
    }
};