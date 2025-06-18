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
    void fillTree(TreeNode* root, vector<int>& levelSum, int level) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        int currLevelSum = levelSum[level];
        if (root->left)
            currLevelSum -= root->left->val;
        if (root->right)
            currLevelSum -= root->right->val;
        if (root->left)
            root->left->val = currLevelSum;
        if (root->right)
            root->right->val = currLevelSum;
        fillTree(root->left, levelSum, level + 1);
        fillTree(root->right, levelSum, level + 1);
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;
        while (!q.empty()) {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            levelSum.push_back(sum);
        }
        fillTree(root, levelSum, 1);
        root->val = 0;
        return root;
    }
};