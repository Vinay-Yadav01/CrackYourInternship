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
    void solve(TreeNode* root, string& temp, int& ans) {
        if (root == NULL)
            return;
        
        if (root->left == NULL && root->right == NULL) {
            temp += to_string(root->val);
            ans += stoi(temp,nullptr,2);
            temp.pop_back();
            return;
        }
        temp += to_string(root->val);
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
        temp.pop_back();
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