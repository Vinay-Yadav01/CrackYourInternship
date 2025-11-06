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
    pair<int, int> solve(TreeNode* root, int& ans) {
        if (!root)
            return {INT_MIN, INT_MAX};
        auto left = solve(root->left, ans);
        auto right = solve(root->right, ans);
        if (left.first != INT_MIN)
            ans = max(ans, abs(root->val - left.first));
        if (left.second != INT_MAX)
            ans = max(ans, abs(root->val - left.second));
        if (right.first != INT_MIN)
            ans = max(ans, abs(root->val - right.first));
        if (right.second != INT_MAX)
            ans = max(ans, abs(root->val - right.second));
        int maxElement = max({root->val, left.first, right.first});
        int minElement = min({root->val, left.second, right.second});
        return {maxElement, minElement};
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};