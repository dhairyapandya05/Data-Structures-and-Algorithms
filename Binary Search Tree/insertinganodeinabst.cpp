https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
        Node* insert(Node* node, int data) {
        
            // Your code goes here
            if(node==NULL){
                return (new Node(data));
            }
            Node* curr=node;
            while(true){
                if(curr->data==data){
                    break;
                }
                if(curr->data>data){
                    if(curr->left){
                        curr=curr->left;
                    }
                    else{
                        curr->left=new Node(data);
                        break;
                    }
                }
                else{
                    if(curr->right){
                        curr=curr->right;
                    }
                    else{
                        curr->right=new Node(data);
                        break;
                    }
                }
            }
            return node;
    }

};