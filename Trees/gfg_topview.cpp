class Solution {
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    map<int, int> mp;
    vector<int> topView(Node *root) {
        // Your code here
        queue<pair<Node *, int>> qe;
        qe.push({root, 0});
        while (!qe.empty()) {
            auto entry = qe.front();
            qe.pop();
            Node *node = entry.first;
            int level = entry.second;
            if (mp.find(level) == mp.end()) {
                mp[level] = node->data;
            }
            if (node->left != NULL) {
                qe.push({node->left, level - 1});
            }
            if (node->right != NULL) {
                qe.push({node->right, level + 1});
            }
        }
        vector<int> topview;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            topview.push_back(it->second);
        }
        return topview;
    }
};
link : https: // www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
              // Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the BFS traversal.

              // Space Complexity: O(N/2 + N/2) where N represents the number of nodes in the Binary Tree.

              // The main space consuming data structure is the queue used for BFS traversal. It acquires space proportional to the number of nodes in the level it is exploring hence in the worst case of a balanced binary tree, the queue will have at most N/2 nodes which is the maximum width.
              // Additionally, the map is used to store the top view nodes based on their vertical positions hence its complexity will also be proportional to the greatest width level. In the worst case, it may have N/2 entries as well.