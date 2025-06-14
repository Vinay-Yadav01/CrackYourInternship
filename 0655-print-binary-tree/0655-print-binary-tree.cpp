class Solution {
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(TreeNode* root, vector<vector<string>>& res, int row, int left, int right) {
        if (!root || left > right) return;
        int mid = (left + right) / 2;
        res[row][mid] = to_string(root->val);
        fill(root->left, res, row + 1, left, mid - 1);
        fill(root->right, res, row + 1, mid + 1, right);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int width = pow(2, height) - 1;
        vector<vector<string>> res(height, vector<string>(width, ""));
        fill(root, res, 0, 0, width - 1);
        return res;
    }
};
