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
    TreeNode* merge(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        if (root1 != NULL && root2 == NULL) {
            TreeNode* temp = new TreeNode(root1->val);
            temp->left = merge(root1->left,NULL);
            temp->right = merge(root1->right, NULL);
            return temp;
        }
        if (root1 == NULL && root2 != NULL) {
            TreeNode* temp = new TreeNode(root2->val);
            temp->left = merge(NULL, root2->left);
            temp->right = merge(NULL, root2->right);
            return temp;
        }
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = merge(root1->left, root2->left);
        root->right = merge(root1->right, root2->right);
        return root;
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};