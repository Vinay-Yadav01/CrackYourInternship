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
    void solve(TreeNode* root, string& ans, string temp) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            temp += (root->val) + 'a';
            reverse(temp.begin(), temp.end());
            if (temp < ans)
                ans = temp;
            return;
        }
        temp += (root->val) + 'a';
        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "~", temp = "";
        solve(root, ans, temp);
        return ans;
    }
};