class Solution {
    bool isSametree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) {
            return root == nullptr && subRoot == nullptr;
        }
        if (root->val != subRoot->val)
            return false;
        return isSametree(root->left, subRoot->left) &&
               isSametree(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (isSametree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
