/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
class Solution {
public:
    map<TreeNode*, TreeNode*> childparent;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            inorder(root->left);
            childparent.insert({root->left, root});
        }

        if (root->right != NULL) {
            inorder(root->right);
            childparent.insert({root->right, root});
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        while (!q.empty()) {
            int n = q.size();
            if (k == 0) {
                break;
            }
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                if (!visited[temp->left] and temp->left != NULL) {
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if (!visited[temp->right] and temp->right != NULL) {
                    q.push(temp->right);
                    visited[temp->right]=true;

                }
                if (!visited[childparent[temp]] and childparent[temp] != NULL) {
                    q.push(childparent[temp]);
                    visited[childparent[temp]]=true;
                }
            }
            k--;
        }
        vector<int> ans;
        while (!q.empty()) {
        TreeNode* fr = q.front();
            ans.push_back(fr->val);
            q.pop();
        }
        return ans;
    }
};