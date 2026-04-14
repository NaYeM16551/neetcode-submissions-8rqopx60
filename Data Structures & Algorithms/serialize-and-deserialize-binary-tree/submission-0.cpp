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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "null,";
            }
        }

        // Remove the trailing comma
        if (!ans.empty()) ans.pop_back();

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        vector<string> values;

        while (getline(ss, item, ',')) {
            values.push_back(item);
        }

        if (values[0] == "null") return nullptr;

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(values[0]));
        q.push(root);
        int i = 1;

        while (!q.empty() && i < values.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < values.size() && values[i] != "null") {
                node->left = new TreeNode(stoi(values[i]));
                q.push(node->left);
            }
            i++;

            if (i < values.size() && values[i] != "null") {
                node->right = new TreeNode(stoi(values[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};
