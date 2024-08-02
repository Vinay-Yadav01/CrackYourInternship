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
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (root == NULL)
            return ans;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long first, last;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front().first;
                unsigned long long val = q.front().second;
                q.pop();
                if (i == 0)
                    first = val;
                if (i == size - 1)
                    last = val;
                if (front->left)
                    q.push({front->left, val * 2 + 1});
                if (front->right)
                    q.push({front->right, val * 2 + 2});
            }
            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};
