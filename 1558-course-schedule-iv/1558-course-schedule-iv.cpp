class Solution {
    void bfs(int uPar, int numCourses, vector<int> adj[],
             vector<vector<bool>>& isReachable) {
        vector<int> vis(numCourses, 0);
        vis[uPar] = 1;
        queue<int> q;
        q.push(uPar);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            isReachable[uPar][node] = true;
            for (int it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);  // Answer size should match queries
        if (prerequisites.empty()) {
            return ans;
        }
        
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++) {  
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        vector<vector<bool>> isReachable(numCourses,
                                         vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; i++) {
            bfs(i, numCourses, adj, isReachable);
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0]; 
            int v = queries[i][1];
            ans[i] = isReachable[u][v];
        }
        
        return ans;
    }
};
