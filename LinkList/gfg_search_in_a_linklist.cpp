class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        Node* curr=head;
        if(head==NULL){
            return false;
        }
        while(curr->next!=NULL){
            if(curr->data==key){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }
};