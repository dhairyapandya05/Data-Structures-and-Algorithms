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
    int maxsum;
    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        int neeche_hi_milgaya_answer = l + r + root->val; //(1)

        int koi_ek_acha = max(l, r) + root->val; //(2)

        int only_root_acha = root->val; //(3)

        maxsum = max({maxsum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});

        // most important part
        return max(koi_ek_acha, only_root_acha);
    }
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        solve(root);
        return maxsum;
    }
};