// https://leetcode.com/problems/maximum-width-of-binary-tree/description/
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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll maxWidth = 0;
        while (!q.empty()) {
            ll n = q.size();
            ll L = q.front().second;
            ll R = q.back().second;
            maxWidth = max(maxWidth, R - L + 1);
            while (n--) {
                auto temp = q.front();
                q.pop();
                TreeNode* element = temp.first;
                ll index = temp.second;
                if (element->left != NULL) {
                    q.push({element->left, 2 * index+1});
                }
                if (element->right != NULL) {
                    q.push({element->right, (2 * index) + 2});
                }
            }
        }
        return maxWidth;
    }
};