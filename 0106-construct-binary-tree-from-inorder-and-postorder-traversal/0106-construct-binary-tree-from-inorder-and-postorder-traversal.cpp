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
    TreeNode* solve(int size, vector<int>& in, vector<int>& post,
                    int& postIndex, int inStart, int inEnd,
                    map<int, int>& index) {
        if (postIndex < 0 || inStart > inEnd)
            return NULL;
        int pos = index[post[postIndex]];
        TreeNode* root = new TreeNode(post[postIndex]);
        postIndex--;

        root->right = solve(size, in, post, postIndex, pos + 1, inEnd, index);
        root->left = solve(size, in, post, postIndex, inStart, pos - 1, index);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int> index;
        for(int i=0;i<n;i++) index[inorder[i]]=i;
        int postIndex = n-1;
        return solve(n, inorder, postorder, postIndex, 0, n-1, index);
    }
};