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
    void traversal(TreeNode* root, int& sum) {
        if (!root)
            return;
        traversal(root->left, sum);
        sum += root->val;
        traversal(root->right, sum);
    }
    void convert(TreeNode* root, int& curSum, int& totalSum) {
        if (!root)
            return;
        convert(root->left, curSum, totalSum);
        int temp = root->val;
        root->val = totalSum - curSum;
        curSum += temp;
        convert(root->right, curSum, totalSum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        traversal(root, sum);
        int curSum = 0;
        convert(root, curSum, sum);
        return root;
    }
};