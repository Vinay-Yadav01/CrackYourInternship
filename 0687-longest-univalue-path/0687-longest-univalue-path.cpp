class Solution {
    int dfs(TreeNode* root, int& ans) {
        if (!root) return 0;

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        int leftPath = 0, rightPath = 0;

        if (root->left && root->left->val == root->val)
            leftPath = left + 1;
        if (root->right && root->right->val == root->val)
            rightPath = right + 1;

        ans = max(ans, leftPath + rightPath); 
        return max(leftPath, rightPath);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
