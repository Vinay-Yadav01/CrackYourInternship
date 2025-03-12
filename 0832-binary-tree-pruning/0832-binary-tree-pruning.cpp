/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* root) {
        if (root == NULL)
            return false;
        bool containOneInLeft = solve(root->left);
        if (!containOneInLeft)
            root->left = NULL;
        bool containOneInRight = solve(root->right);
        if (!containOneInRight)
            root->right = NULL;
        return root->val || containOneInLeft || containOneInRight;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        bool containOne = solve(root);
        if(!containOne) return NULL;
        return root;
    }
};