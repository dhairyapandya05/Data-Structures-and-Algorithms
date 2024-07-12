/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data>head2->data){
        result=head2;
        head2->next=sortedMerge(head1,head2->next);
    }
    else{
        result=head1;
        head1->next=sortedMerge(head1->next,head2);
    }
    return result;
}  