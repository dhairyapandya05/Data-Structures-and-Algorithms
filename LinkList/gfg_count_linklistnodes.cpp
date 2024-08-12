class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        if(head==NULL){
            return 0;
        }
        // Code here
        Node* curr=head;
        int count=1;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        return count;
    }
};