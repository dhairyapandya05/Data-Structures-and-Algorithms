class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        // Code here
        if(head==NULL or head->next==NULL){
            return 0;
        }
        bool cycledetected=false;
        Node* fast=head;
        Node* slow=head;
        while(fast->next!=NULL and slow->next!=NULL){
            fast=fast->next;
            slow=slow->next;
            if(fast->next!=NULL){
                fast=fast->next;
                if(fast==slow){
                    cycledetected=true;
                    break;
                }
            }
        }
        if(!cycledetected){
            return 0;
        }
        int cnt=1;
        fast=fast->next;
        while(fast!=slow){
            cnt++;
            fast=fast->next;
        }
        return cnt;
    }
};