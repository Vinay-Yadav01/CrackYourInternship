/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> arr;
    void inorder(TreeNode* root){
       if(!root) return;
       inorder(root->left);
       arr.push_back(root->val);
       inorder(root->right);
    }

    TreeNode* balanceBST(const int l, const int r){
        if (l>r) return NULL;
        int m=(l+r)/2;
        TreeNode* left=balanceBST(l, m-1);
        TreeNode* right=balanceBST(m+1, r);
        return new TreeNode(arr[m], left, right);
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return balanceBST(0, arr.size()-1);
    }
};
