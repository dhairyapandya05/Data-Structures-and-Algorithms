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
    ListNode* reverse(ListNode* head){
        ListNode* curr =head;
        ListNode* prev = NULL;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //this can be solved in 3 easy steps
        // step  1 finding the mideele node

        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL){
            fast=fast->next;

            if(fast!=NULL && fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        //at this point the slow pointer is pointing to the middle node
        slow->next=reverse(slow->next);
        ListNode* checkmid=slow->next;
        ListNode* checkstart=head;
        while(checkmid!=NULL){
            if(checkmid->val!=checkstart->val){
                return false; 
            }
            else{
                checkmid=checkmid->next;
                checkstart=checkstart->next;
            }
        }
        return true;
    }
};