class Solution {
    int topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int total = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            total++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return total;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        int ans = topoSort(n, adj);
        if (ans != n)
            return false;
        return true;
    }
};