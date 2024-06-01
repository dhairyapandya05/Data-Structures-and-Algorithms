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
    void inorder(TreeNode* root,string& s){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL and root->right==NULL){
            s+=(root->val)+'_';
        }
        inorder(root->left,s);
        inorder(root->right,s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1;
        string s2;
        inorder(root1,s1);
        inorder(root2,s2);
        return s1==s2;
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
    void inordertraversal(TreeNode* root,vector<int>&order){
        if(root==NULL){
            return;
        }
        if(root->right==NULL and root->left==NULL){
            order.push_back(root->val);
        }
        inordertraversal(root->left,order);
        inordertraversal(root->right,order);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> order1;
        vector<int> order2;
        inordertraversal(root1,order1);
        inordertraversal(root2,order2);
        if(order1.size()==order2.size()){
            for(int i=0;i<order1.size();i++){
                if(order1[i]!=order2[i]){
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
};