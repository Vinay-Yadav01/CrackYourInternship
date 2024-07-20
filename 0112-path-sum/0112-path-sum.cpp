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
    bool pathSum(TreeNode* root, int targetSum, int currentSum) {
        if(root==NULL) return false;
        if (root->left == NULL && root->right == NULL) {
            currentSum += root->val;
            return currentSum == targetSum;
        }
        bool left = pathSum(root->left, targetSum, currentSum + root->val);
        bool right =
                pathSum(root->right, targetSum, currentSum + root->val);
        return left || right;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;
        return pathSum(root, targetSum, 0);
    }
};