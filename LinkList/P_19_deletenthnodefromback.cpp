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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        while (n--) {
            fast = fast->next;
        }
        if(fast==NULL){//this is a important case means we have reached the end of the linkedlist
            return head->next;
        }
        while (fast != NULL and fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
// Method 2
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
    int lengthLL(ListNode* head){
        int cnt=0;
        ListNode* curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        int length=lengthLL(head);
        if(length<n){
            return NULL;
        }
        ListNode* curr=head;
        if(n==length){
            head=head->next;
            return head;
        }
        int threshold=length-n;
        while(threshold>1 and curr!=NULL){
            threshold--;
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};