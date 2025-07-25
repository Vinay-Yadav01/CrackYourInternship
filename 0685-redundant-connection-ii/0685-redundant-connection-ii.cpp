class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> laterEdge, earlierEdge;
        vector<int> parent(n + 1, -1);
        // Step1: Find parent
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (parent[v] == -1)
                parent[v] = u;
            else {
                earlierEdge = {parent[v], v};
                laterEdge = {u, v};
            }
        }
        // Step2: Check cycle for verification
        DisjointSet ds(n);
        bool cycleCheck = false;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!laterEdge.empty() && u == laterEdge[0] && v == laterEdge[1])
                continue;
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cycleCheck = true;
                if (earlierEdge.empty())
                    earlierEdge = {u, v};
                break;
            } else
                ds.unionBySize(u, v);
        }
        return cycleCheck ? earlierEdge : laterEdge;
    }
};