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
        string ans = "";
        if (root == NULL) {
            return "";
        }
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty()) {
            auto it = qe.front();
            qe.pop();
            if (it == NULL) {
                ans.append("#,");
            }
            if (it != NULL) {
                ans.append(to_string(it->val) + ',');
                qe.push(it->left);
                qe.push(it->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        queue<TreeNode*> qe;
        string str;
        stringstream s(data);
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        qe.push(root);
        while (!qe.empty()) {
            TreeNode* node = qe.front();
            qe.pop();
            getline(s, str, ',');
            if (str == "#") {
                node->left = NULL;
            } else {
                TreeNode* root = new TreeNode(stoi(str));
                node->left = root;
                qe.push(root);
            }
            getline(s, str, ',');
            if (str == "#") {
                node->right = NULL;
            } else {
                TreeNode* root = new TreeNode(stoi(str));
                node->right = root;
                qe.push(root);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));