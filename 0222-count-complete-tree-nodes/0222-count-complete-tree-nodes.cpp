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
    int leftHeight(TreeNode* root){
        if(root==NULL) return 0;
        int ans=0;
        while(root){
            ans++;
            root=root->left;
        }
        return ans;
    }
    int rightHeight(TreeNode* root){
        if(root==NULL) return 0;
        int ans=0;
        while(root){
            ans++;
            root=root->right;
        }
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int leftH = leftHeight(root->left);
        int rightH = rightHeight(root->right);
        if(leftH == rightH) return pow(2,leftH+1)-1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};