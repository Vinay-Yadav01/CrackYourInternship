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
    vector<TreeNode*> result;
    set<int> to_delete_set;
    TreeNode* solve(TreeNode* node, vector<TreeNode*>& result,
                    set<int>& to_delete_set, bool is_root) {
        if (node == NULL)
            return NULL;
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted)
            result.push_back(node);
        node->left = solve(node->left, result, to_delete_set, deleted);
        node->right = solve(node->right, result, to_delete_set, deleted);
        return deleted ? NULL : node;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            to_delete_set.insert(i);
        solve(root, result, to_delete_set, true);
        return result;
    }
};