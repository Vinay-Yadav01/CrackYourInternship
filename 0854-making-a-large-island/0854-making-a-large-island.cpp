class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
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
private:
    bool isValid(int adjRow, int adjCol, int n) {
        return adjRow >= 0 && adjCol >= 0 && adjRow < n && adjCol < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step-1: Making clusters
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                for (int i = 0; i < 4; i++) {
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];
                    if (isValid(adjRow, adjCol, n)) {
                        if (grid[adjRow][adjCol] == 1) {
                            int node = row * n + col;
                            int adjNode = adjRow * n + adjCol;
                            if (ds.findUPar(node) != ds.findUPar(adjNode)) {
                                ds.unionBySize(node, adjNode);
                            }
                        }
                    }
                }
            }
        }

        // Step-2: Taking each zeroes and count maximum cluster
        int maxi = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];
                    if (isValid(adjRow, adjCol, n)) {
                        if (grid[adjRow][adjCol] == 1) {
                            components.insert(ds.findUPar(adjRow * n + adjCol));
                        }
                    }
                }
                int totalSize = 0;
                for (auto it : components) {
                    totalSize += ds.size[it];
                }
                totalSize += 1; // That 0 -> 1
                maxi = max(maxi, totalSize);
            }
        }

        // Checking if there all 1

        for (int cell = 0; cell < n * n; cell++) {
            maxi = max(maxi, ds.size[ds.findUPar(cell)]);
        }

        return maxi;
    }
};