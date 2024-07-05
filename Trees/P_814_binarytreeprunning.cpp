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
    bool isOnepresent(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        if (root->val == 1) {
            return true;
        }
        return isOnepresent(root->left) or isOnepresent(root->right);
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        if (!isOnepresent(root->left)) {
            root->left = NULL;
        }
        if (!isOnepresent(root->right)) {
            root->right = NULL;
        }
        if (root->left != NULL) {
            root->left = pruneTree(root->left);
        }
        if (root->right != NULL) {
            root->right = pruneTree(root->right);
        }
        if(root->left==NULL and root->right==NULL and root->val==0){
            return NULL;
        } 
        return root;
    }
};


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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(root->left!=NULL){
            root->left=pruneTree(root->left);
        }
        if(root->right!=NULL){
            root->right=pruneTree(root->right);
        }
        if(root->left==NULL and root->right==NULL and root->val==0){
            return NULL;
        }
        return root;
    }
};