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
        if (!root->left && !root->right) {
            ans++;
            return {root->val, 1};
        }
        int numberOfElement = 1, totalSum = root->val;
        if (root->left) {
            auto [sum, count] = solve(root->left, ans);
            numberOfElement += count;
            totalSum += sum;
        }
        if (root->right) {
            auto [sum, count] = solve(root->right, ans);
            numberOfElement += count;
            totalSum += sum;
        }
        int avg = totalSum / numberOfElement;
        if (root->val == avg)
            ans++;
        return {totalSum, numberOfElement};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};