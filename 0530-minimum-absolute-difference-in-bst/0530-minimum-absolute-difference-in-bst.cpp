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
private:
    void traversal(TreeNode* root, vector<int> & arr){
        if(root==NULL) return;
        traversal(root->left, arr);
        arr.push_back(root->val);
        traversal(root->right,arr);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        traversal(root, arr);
        int ans=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            ans = min(ans, abs(arr[i]-arr[i+1]));
        }
        return ans;
    }
};