// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int maxlevel=0;
        int sum=INT_MIN;
        int maxsum=INT_MIN;
        while (!q.empty()) {
            int n = q.size();
            sum = 0;
            level++;
            while (n--) {
                TreeNode* temp = q.front();
                sum += temp->val;

                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            if(sum>maxsum){
                maxsum=sum;
                maxlevel=level;
            }
        }
        return maxlevel;
    }
};