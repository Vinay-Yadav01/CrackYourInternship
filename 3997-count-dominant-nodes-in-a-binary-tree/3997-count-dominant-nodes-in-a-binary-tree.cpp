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
    int solve(TreeNode* root, int& ans) {
        if (!root)
            return -1e8;
        if (!root->left && !root->right) {
            ans++;
            return root->val;
        }
        int maxVal = solve(root->left, ans);
        maxVal = max(maxVal, solve(root->right, ans));
        int curVal = root->val;
        if (curVal >= maxVal)
            ans++;
        return max(maxVal, curVal);
    }

public:
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};