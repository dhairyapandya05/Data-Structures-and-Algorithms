class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Define a helper function to calculate the diameter recursively
        int res = 0;
        diameter(root, res);
        return res;
    }
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.
private:
    int diameter(TreeNode* curr, int& res){
        // Base case: if the current node is null, return 0
        if (!curr) return 0;
        
        // Recursively calculate the diameter of left and right subtrees
        int left = diameter(curr->left, res);
        int right = diameter(curr->right, res);

        // Update the maximum diameter encountered so far
        res = max(res, left + right);
        
        // Return the depth of the current node
        return max(left, right) + 1;
    }
};
// https://leetcode.com/problems/diameter-of-binary-tree/