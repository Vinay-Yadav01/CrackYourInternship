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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            if (level % 2 == 0) {
                int n = q.size();
                for (int i = 0; i < n; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
            } else {
                int n = q.size();
                vector<TreeNode*> nodes;
                for (int i = 0; i < n; i++) {
                    TreeNode* node = q.front();
                    nodes.push_back(node);
                    q.pop();
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                int i = 0, j = n - 1;
                while (i < j) {
                    swap(nodes[i]->val, nodes[j]->val);
                    ++i;
                    --j;
                }
            }
            level++;
        }
        return root;
    }
};