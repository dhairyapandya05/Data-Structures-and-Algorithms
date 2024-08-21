class Solution {
  public:
  Node* mergeLL(Node* a,Node* b){
      Node* res=new Node(0);
      Node* temp=res;
      while(a!=NULL and b!=NULL){
          if(a->data<b->data){
              temp->bottom=a;
              temp=temp->bottom;
              a=a->bottom;
          }
          else{
              temp->bottom=b;
              temp=temp->bottom;
              b=b->bottom;
          }
      }
      if(a!=NULL){
          temp->bottom=a;
      }
      else{
          temp->bottom=b;
      }
      return res->bottom;
  }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL or root->next==NULL){
            return root;
        }
        root->next=flatten(root->next);
        root=mergeLL(root,root->next);
        return root;
    }
};
// link:https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1