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
    void solve(TreeNode* root, long& firstMin, long& secondMin) {
        if (root == NULL)
            return;
        if (root->val < firstMin) {
            secondMin = firstMin;
            firstMin = root->val;
        } else if (root->val < secondMin && root->val != firstMin) {
            secondMin = root->val;
        }
        solve(root->left, firstMin, secondMin);
        solve(root->right, firstMin, secondMin);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        long firstMin = LONG_MAX, secondMin = LONG_MAX;
        solve(root, firstMin, secondMin);
        return (secondMin != LONG_MAX) ? secondMin : -1;
    }
};