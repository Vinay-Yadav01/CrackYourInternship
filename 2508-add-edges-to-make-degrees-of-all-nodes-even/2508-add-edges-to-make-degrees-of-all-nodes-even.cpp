class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        for (auto& it : edges) {
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }

        vector<int> oddDegree;
        for (int i = 1; i <= n; i++) { 
            if (adj[i].size() % 2 == 1)
                oddDegree.push_back(i);
        }

        int sz = oddDegree.size();
        if (sz == 0)
            return true;
        if (sz == 1 || sz == 3 || sz > 4)
            return false;

        if (sz == 2) {
            int a = oddDegree[0], b = oddDegree[1];
            // directly connect them if edge doesn't exist
            if (!adj[a].count(b))
                return true;
            // try a third node v that is not connected to either a or b
            for (int v = 1; v <= n; v++) {
                if (v == a || v == b)
                    continue;
                if (!adj[a].count(v) && !adj[b].count(v))
                    return true;
            }
            return false;
        }

        // sz == 4
        int a = oddDegree[0], b = oddDegree[1];
        int c = oddDegree[2], d = oddDegree[3];

        // pairing 1: (a-b) and (c-d)
        if (!adj[a].count(b) && !adj[c].count(d))
            return true;
        // pairing 2: (a-c) and (b-d)
        if (!adj[a].count(c) && !adj[b].count(d))
            return true;
        // pairing 3: (a-d) and (b-c)
        if (!adj[a].count(d) && !adj[b].count(c))
            return true;

        return false;
    }
};
