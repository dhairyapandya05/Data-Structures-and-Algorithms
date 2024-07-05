class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        map<int, int> childtoparent;
        map<int, vector<int>> adjacencylist;
        for (int i = 0; i < n; i++) {

            if (leftChild[i] != -1) {
                adjacencylist[i].push_back(leftChild[i]);
                if (childtoparent.find(leftChild[i]) != childtoparent.end()) {
                    return false;
                }
                childtoparent.insert({leftChild[i], i});
            }
            if (rightChild[i] != -1) {
                adjacencylist[i].push_back(rightChild[i]);
                if (childtoparent.find(rightChild[i]) != childtoparent.end()) {
                    return false;
                }
                childtoparent.insert({rightChild[i], i});
            }
        }
        // 1 child 1 parent check
        if (n - childtoparent.size() != 1) {
            return false;
        }
        // findingthe root
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (childtoparent.find(i) == childtoparent.end()) {
                if (root == -1) {
                    root = i;
                } else {
                    return false; // More than one root found
                }
            }
        }
        if (root == -1) {
            return false; // No root found
        }
        // allnodes should be connected and number of nodes counted should be
        // equal to n
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(root);
        visited[root] = true;
        int count = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int temp = q.front();
                q.pop();
                for (int& v : adjacencylist[temp]) {
                    if (visited[v] == false) {
                        visited[v] = true;
                        q.push(v);
                        count++;
                    }
                }
            }
        }
        return n == count;
    }
};