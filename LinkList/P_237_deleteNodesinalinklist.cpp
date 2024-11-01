/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        ListNode* curr = node;
        curr->val = curr->next->val;
        curr = curr->next;
        while (curr->next != NULL) {
            curr->val = curr->next->val;
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
    }
};