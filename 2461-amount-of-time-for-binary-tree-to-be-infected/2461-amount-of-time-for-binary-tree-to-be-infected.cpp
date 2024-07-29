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
    TreeNode* mapping(map<TreeNode*, TreeNode*>& parent, TreeNode* root,
                      int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = NULL;
        parent[root] = NULL;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front->val == start)
                res = front;
            if (front->left) {
                q.push(front->left);
                parent[front->left] = front;
            }
            if (front->right) {
                q.push(front->right);
                parent[front->right] = front;
            }
        }
        return res;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = mapping(parent, root, start);
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;
        q.push(startNode);
        visited[startNode] = true;
        int ans = 0;        
        while (!q.empty()) {
            int flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    flag=1;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    flag=1;
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                    flag=1;
                }
            }
            if(flag==1) ans++;
        }
        return ans;
    }
};