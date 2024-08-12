class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head==NULL){
            head=new Node(x);
            return head;
        }
        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=new Node(x);
        return head;
    }
};
// link:https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion
