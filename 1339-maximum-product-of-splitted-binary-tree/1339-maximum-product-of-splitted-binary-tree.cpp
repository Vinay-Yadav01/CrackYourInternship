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
    long long mod = 1e9 + 7;
    void totalSum(TreeNode* root, long long& total_sum) {
        if (!root)
            return;
        total_sum += root->val;
        totalSum(root->left, total_sum);
        totalSum(root->right, total_sum);
    }

    long long solve(TreeNode* root, long long& total_sum, long long& maxPro) {
        if (!root)
            return 0;
        long long curr_sum = root->val;
        curr_sum += solve(root->left, total_sum, maxPro);
        curr_sum += solve(root->right, total_sum, maxPro);
        maxPro = max(maxPro, (total_sum - curr_sum) * curr_sum);
        return curr_sum;
    }

public:
    int maxProduct(TreeNode* root) {
        long long total_sum = 0;
        totalSum(root, total_sum);
        long long maxProd = LLONG_MIN;
        solve(root, total_sum, maxProd);
        return (int)(maxProd % mod);
    }
};