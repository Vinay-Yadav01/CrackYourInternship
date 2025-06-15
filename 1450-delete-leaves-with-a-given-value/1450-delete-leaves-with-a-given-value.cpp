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
    bool solve(TreeNode* root, int target) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL && root->val == target)
            return true;
        bool leftAns = solve(root->left, target);
        if (leftAns)
            root->left = NULL;
        bool rightAns = solve(root->right, target);
        if (rightAns)
            root->right = NULL;
        return leftAns && rightAns && root->val == target;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool ans = solve(root, target);
        if (ans)
            return NULL;
        return root;
    }
};