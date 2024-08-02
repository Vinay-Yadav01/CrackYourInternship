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
private:
    void solve(TreeNode* root, int num, int& sum) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            num = num * 10 + root->val;
            sum += num;
            return;
        }
        num = num * 10 + root->val;
        solve(root->left, num, sum);
        solve(root->right, num, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int num = 0, sum = 0;
        solve(root, num, sum);
        return sum;
    }
};