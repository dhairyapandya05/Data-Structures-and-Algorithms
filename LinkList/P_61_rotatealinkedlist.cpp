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
    int lengthLL(ListNode* curr){
        int cnt=0;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        int length=lengthLL(head);
        if(k%length==0){
            return head;
        }
        ListNode* curr=head;
        int moves=length-(k%length)-1;
        while(moves--){
            curr=curr->next;
        }
        ListNode* newhead=curr->next;
        ListNode* currtemp=newhead;
        curr->next=NULL;
        while(currtemp->next!=NULL){
            currtemp=currtemp->next;
        }
        currtemp->next=head;
        return newhead;
    }
};