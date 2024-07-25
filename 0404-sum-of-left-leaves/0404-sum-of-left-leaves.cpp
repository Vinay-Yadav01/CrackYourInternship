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
    int sum(TreeNode* root, bool isLeft){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            if(isLeft) return root->val;
            else return 0;
        }
        int ans=0;
        ans+=sum(root->left,true);
        ans+=sum(root->right,false);
        return ans;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(root==NULL) return -1;
        if(root->left==NULL && root->right==NULL) return ans;
        ans+=sum(root->left, true);
        ans+=sum(root->right, false);
        return ans;
    }
};