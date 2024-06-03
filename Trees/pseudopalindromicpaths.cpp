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
    int ans=0;
    void solution(TreeNode* root,vector<int>& mp){
        if(root==NULL){
            return;
        }
        mp[root->val]++;
        if(root->left==NULL and root->right==NULL){
            int odd_occurances=0;
            for(int i=1;i<=9;i++){
                if(mp[i]%2==1){
                    ++odd_occurances;
                }
            }
            if(odd_occurances<=1){
                ans++;
            }
        }
        solution(root->left,mp);
        solution(root->right,mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10,0);
        solution(root,mp);
        return ans;
    }
};
// 1457. Pseudo-Palindromic Paths in a Binary Tree