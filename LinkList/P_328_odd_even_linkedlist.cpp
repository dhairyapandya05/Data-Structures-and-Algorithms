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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        vector<int> ans;
        ListNode* curr=head;
        while(curr!=NULL and curr->next!=NULL){
            ans.push_back(curr->val);
            curr=curr->next->next;
        }
        if(curr!=NULL){
            ans.push_back(curr->val);
        }
        curr=head->next;
        while(curr!=NULL and curr->next!=NULL){
            ans.push_back(curr->val);
            curr=curr->next->next;
        }
        if(curr!=NULL){
            ans.push_back(curr->val);
        }
        curr=head;
        int i=0;
        while(curr!=NULL){
            curr->val=ans[i];
            i++;
            curr=curr->next;
        }
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *oddptr = head, *evenptr = head->next, *evenPTR = head->next;
        while (evenptr != NULL and evenptr->next != NULL) {
            oddptr->next = oddptr->next->next;
            evenptr->next = evenptr->next->next;
            oddptr = oddptr->next;
            evenptr = evenptr->next;
        }
        oddptr->next = evenPTR;
        return head;
    }
};