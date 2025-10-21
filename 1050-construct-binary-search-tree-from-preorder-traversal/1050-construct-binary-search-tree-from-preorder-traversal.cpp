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
    TreeNode* createBST(vector<int>& pre, vector<int>& in, int size,
                        int& preIndex, int inStart, int inEnd,
                        map<int, int>& index) {
        if (preIndex >= size || inStart > inEnd)
            return NULL;
        int pos = index[pre[preIndex]];
        TreeNode* root = new TreeNode(pre[preIndex]);
        preIndex++;

        root->left =
            createBST(pre, in, size, preIndex, inStart, pos - 1, index);
        root->right = createBST(pre, in, size, preIndex, pos + 1, inEnd, index);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int n = inorder.size();
        map<int, int> index;
        for (int i = 0; i < n; i++)
            index[inorder[i]] = i;
        int preIndex = 0;
        return createBST(preorder, inorder, n, preIndex, 0, n - 1, index);
    }
};