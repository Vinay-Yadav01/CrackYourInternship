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
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        if (root == NULL)
            return ans;
        if (root->left == NULL && root->right == NULL) {
            ans += to_string(root->val);
            return ans;
        }
        ans+=to_string(root->val);
        string rightAns = tree2str(root->right);
        string leftAns = tree2str(root->left);
        if (rightAns != "") {
            ans += "(" + leftAns + ")";
            ans += "(" + rightAns + ")";
        }
        else ans += "(" + leftAns + ")";
        return ans;
    }
};