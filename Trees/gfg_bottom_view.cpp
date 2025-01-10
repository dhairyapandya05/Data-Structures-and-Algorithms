class Solution {
public:
    map<int, int> mp;
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node *, int>> qe;
        qe.push({root, 0});
        // mp[0]=root->val;
        while (!qe.empty()) {
            int n = qe.size();
            while (n--) {
                auto frontent = qe.front();
                Node *frontNode = frontent.first;
                int col = frontent.second;
                mp[col] = frontNode->data;
                qe.pop();
                if (frontNode->left != NULL) {
                    qe.push({frontNode->left, col - 1});
                }
                if (frontNode->right != NULL) {
                    qe.push({frontNode->right, col + 1});
                }
            }
        }
        vector<int> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the BFS traversal.

// Space Complexity: O(N/2 + N/2) where N represents the number of nodes in the Binary Tree.

// The main space consuming data structure is the queue used for BFS traversal. It acquires space proportional to the number of nodes in the level it is exploring hence in the worst case of a balanced binary tree, the queue will have at most N/2 nodes which is the maximum width.
// Additionally, the map is used to store the top view nodes based on their vertical positions hence its complexity will also be proportional to the greatest width level. In the worst case, it may have N/2 entries as well.