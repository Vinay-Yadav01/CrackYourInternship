class Solution {
    int dfs(int node, int parent, const vector<vector<int>>& tree,
            vector<int>& subtree_size, int& good_nodes_count) {
        int size = 1; // Start with the current node
        int first_child_size = -1;
        bool is_good = true;

        for (int neighbor : tree[node]) {
            if (neighbor == parent)
                continue;

            int child_size =
                dfs(neighbor, node, tree, subtree_size, good_nodes_count);
            size += child_size;

            // Check if all child subtrees are of the same size
            if (first_child_size == -1) {
                first_child_size = child_size;
            } else if (first_child_size != child_size) {
                is_good = false;
            }
        }

        subtree_size[node] = size;

        // Mark node as good if all child subtrees have the same size
        if (is_good) {
            good_nodes_count++;
        }

        return size;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;  // Number of nodes
        vector<vector<int>> tree(n);
        vector<int> subtree_size(n, 0);
        int good_nodes_count = 0;

        // Build the adjacency list
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Start DFS from the root node (0)
        dfs(0, -1, tree, subtree_size, good_nodes_count);

        return good_nodes_count;
    }
};
