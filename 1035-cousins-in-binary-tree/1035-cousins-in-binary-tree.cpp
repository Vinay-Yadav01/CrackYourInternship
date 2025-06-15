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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<pair<TreeNode*, TreeNode*>> q; // {node, parent}
        q.push({root, nullptr});
        
        while (!q.empty()) {
            int size = q.size();
            TreeNode* x_parent = nullptr;
            TreeNode* y_parent = nullptr;
            for (int i = 0; i < size; ++i) {
                auto [node, parent] = q.front();
                q.pop();
                
                if (node->val == x) x_parent = parent;
                if (node->val == y) y_parent = parent;

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            // Check if both x and y were found at this level
            if (x_parent && y_parent)
                return x_parent != y_parent;
            if (x_parent || y_parent)
                return false; // Found only one at this level
        }

        return false;
    }
};