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
    string output = "";
    void solution(TreeNode* root, string str) {
        if (root == NULL) {
            return;
        }
        str = char(root->val + 'a') + str;//O(len(curr))
        if (root->left==NULL and root->right==NULL) {
            if (output == "" or output > str) {
                output = str;
            }
            return;
        }
        solution(root->left, str);
        solution(root->right, str);
    }
    string smallestFromLeaf(TreeNode* root) {
        string str;
        solution(root, str);
        return output;
    }
};
// TC=O(n)
// SC=O(n)
// dfs approach


// bfs approach
// TC=O(n)
// SC=O(n)
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
    string smallestFromLeaf(TreeNode* root) {
        // queue<root,str>
        queue<pair<TreeNode*, string>> q;
        q.push({root, string(1, char(root->val + 'a'))});
        string output = "";
        while (!q.empty()) {
            auto [node, curr] = q.front();
            q.pop();
            if (node->left == NULL and node->right == NULL) {
                if (output == "" or output > curr) {
                    output = curr;
                }
            }
            if (node->left != NULL) {
                q.push({node->left, char(node->left->val + 'a') + curr});
            }
            if (node->right != NULL) {
                q.push({node->right, char(node->right->val + 'a') + curr});
            }
        }
        return output;
    }
};
