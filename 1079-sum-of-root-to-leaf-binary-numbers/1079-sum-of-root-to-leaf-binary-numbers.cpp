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
    void solve(TreeNode* root, string temp, int& ans) {
        if (root == NULL)
            return;
        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans += stoi(temp,nullptr,2);
            return;
        }
        if (root->left)
            solve(root->left, temp, ans);
        if (root->right)
            solve(root->right, temp, ans);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return root->val;
        string temp = "";
        int ans = 0;
        solve(root, temp, ans);
        return ans;
    }
};