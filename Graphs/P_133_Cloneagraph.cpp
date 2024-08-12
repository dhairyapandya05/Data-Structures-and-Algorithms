/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    void dfs(Node* node,Node* newNode){
        for(Node* n:node->neighbors){
            if(mp.find(n)==mp.end()){
                //this particular node is not present in the map
                Node* cloneNode=new Node(n->val);
                mp[n]=cloneNode;
                newNode->neighbors.push_back(cloneNode);
                dfs(n,cloneNode);
            }
            else{
                newNode->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node* newNode= new Node(node->val);
        mp[node]=newNode;
        dfs(node,newNode);
        return mp[node];
    }
};