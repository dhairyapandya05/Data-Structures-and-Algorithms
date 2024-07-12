class Solution
{
    public:
    struct Node* reverseList(struct Node* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        Node* last = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
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
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node* head=sortedMerge(node1,node2);
        Node* finalhead=reverseList(head);
        return finalhead;
    }  
};