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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* originalhead = new ListNode(0, head);
        ListNode* prev = originalhead;
        prev->next = head;
        ListNode* i = head;
        while (i != NULL) {
            bool isDuplicate = false;
            while (i->next != NULL && i->val == i->next->val) {
                i = i->next;
                isDuplicate = true;
            }
            if (isDuplicate) {
                prev->next = i->next;
            } else {
                prev = prev->next;
            }
            i = i->next;
        }
        return originalhead->next;
    }
};