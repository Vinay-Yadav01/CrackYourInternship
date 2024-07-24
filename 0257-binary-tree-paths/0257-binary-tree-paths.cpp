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
    void solve(TreeNode* root, string temp, vector<string>& ans) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            temp = temp + "->" + to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp = temp + "->" + to_string(root->val);
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)
            return ans;
        string temp = "";
        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return ans;
        }
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
        return ans;
    }
};