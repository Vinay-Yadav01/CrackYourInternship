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
public:
    void solve(TreeNode* root, int currMax, int& count) {
        if (root == NULL)
            return;
        if (root->val >= currMax) {
            count++;
        }
        solve(root->left, max(currMax, root->val), count);
        solve(root->right, max(currMax, root->val), count);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root, root->val, count);
        return count;
    }
};