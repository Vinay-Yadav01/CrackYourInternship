class Solution {
    void dfs(int node, vector<int>& vis, vector<int>& edges, unordered_map<int,int> &dist,
             int& longest) {
        vis[node] = 1;
        int nbr = edges[node];
        if (nbr != -1 && !vis[nbr]) {
            dist[nbr] = dist[node] + 1;
            dfs(nbr, vis, edges, dist, longest);
        } else if (nbr != -1 && dist[nbr]!=0) {
            longest = max(longest, dist[node] - dist[nbr] + 1);
        }
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int longest = -1;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int,int> dist;
                dist[i] = 1;
                dfs(i, vis, edges, dist, longest);
            }
        }
        return longest;
    }
};