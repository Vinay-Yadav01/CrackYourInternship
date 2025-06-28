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
    int steps = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int leftRequired = dfs(root->left);
        int rightRequired = dfs(root->right);

        steps += abs(leftRequired) + abs(rightRequired);
        return (root->val - 1 + leftRequired + rightRequired);
    }

public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps;
    }
};