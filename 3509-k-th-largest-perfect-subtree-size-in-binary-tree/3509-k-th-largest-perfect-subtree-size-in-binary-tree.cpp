/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to determine if the tree rooted at 'node' is a perfect binary subtree
    // and return its size.
    pair<bool, int> checkPerfect(TreeNode* node, int& level) {
        if (!node) {
            return {true, 0}; // An empty tree is considered perfect with size 0.
        }

        // Recursively check the left and right subtrees.
        auto left = checkPerfect(node->left, level);
        auto right = checkPerfect(node->right, level);

        // A node is the root of a perfect binary tree if:
        // 1. Both left and right subtrees are perfect.
        // 2. Both left and right subtrees have the same size.
        if (left.first && right.first && left.second == right.second) {
            int size = left.second + right.second + 1;
            level = max(level, size);
            return {true, size}; // Return that this subtree is perfect and its size.
        }

        return {false, 0}; // Not a perfect binary subtree.
    }

    // Traverse the tree and collect sizes of all perfect subtrees.
    void collectPerfectSubtreeSizes(TreeNode* node, vector<int>& sizes) {
        if (!node) return;

        int level = 0;
        auto res = checkPerfect(node, level);
        if (res.first) {
            sizes.push_back(res.second);
        }

        // Continue traversing the tree.
        collectPerfectSubtreeSizes(node->left, sizes);
        collectPerfectSubtreeSizes(node->right, sizes);
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;
        collectPerfectSubtreeSizes(root, sizes);

        // Sort the sizes in decreasing order.
        sort(sizes.rbegin(), sizes.rend());

        // If there are fewer than k perfect subtrees, return -1.
        if (sizes.size() < k) return -1;

        // Return the k-th largest size.
        return sizes[k - 1];
    }
};