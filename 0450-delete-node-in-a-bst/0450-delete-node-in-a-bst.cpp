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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL)
                return NULL; // 0-Child

            // 1-Child
            else if (root->left != NULL && root->right == NULL) {
                return root->left;
            } else if (root->left == NULL && root->right != NULL) {
                return root->right;
            }

            // 2-Child
            TreeNode* temp = root->right;
            while (temp->left)
                temp = temp->left;
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            root->left = deleteNode(root->left, key);
            return root;
        }
    }
};