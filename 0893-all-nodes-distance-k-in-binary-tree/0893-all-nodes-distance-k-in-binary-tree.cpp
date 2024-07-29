/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void mapping(map<TreeNode*,TreeNode*> &parent, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
                parent[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                parent[front->right] = front;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        mapping(parent, root);
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        while (!q.empty() && k > 0) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* front = q.front();
                q.pop();
                
                if (front->left && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if (parent[front] && !visited[parent[front]]) {
                    q.push(parent[front]);
                    visited[parent[front]] = true;
                }
            }
            k--;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};