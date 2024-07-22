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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> map; // it is a map od int and address (int stores the value of the node and address stores the address odthe tree node)
        set<int> childNodes;
        for (int i = 0; i < n; i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            if (map.find(parent) == map.end())
                map[parent] = new TreeNode(parent);
            if (map.find(child) == map.end())
                map[child] = new TreeNode(child);

            if (isLeft)
                map[parent]->left = map[child];
            else
                map[parent]->right = map[child];
            childNodes.insert(child);
        }
        for (auto it : descriptions) {
            if (childNodes.find(it[0]) == childNodes.end())
                return map[it[0]];
        }
        return NULL; // this will never be executed
    }
};