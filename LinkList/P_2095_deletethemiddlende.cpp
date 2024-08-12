/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return NULL;
        }
        ListNode* slow=head,*slowprev=NULL,*fast=head;
        while(slow->next!=NULL and fast->next!=NULL){
            fast=fast->next;
            slowprev=slow;
            slow=slow->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            else{
                break;
            }
        }
        //at this point I will have to delete the slow ptr
        slowprev->next=slowprev->next->next;
        return head;
    }
};