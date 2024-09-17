/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                ans += "N,";
            } else {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');

        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, item, ','))
                break;
            if (item == "N") {
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(item));
                node->left = leftNode;
                q.push(leftNode);
            }

            if (!getline(ss, item, ','))
                break;
            if (item == "N") {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(item));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;