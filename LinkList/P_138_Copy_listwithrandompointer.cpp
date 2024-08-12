/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            // curr->next->random=curr->random;
            curr->next->next = temp;
            curr = temp;
        }
        // step 2---deep copy of pointers
        curr = head;
        while (curr != NULL and curr->next != NULL) {
            if (curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // step 3 seperate the new list with old one
        Node* newcurr = head->next;
        curr=head;
        Node* newHead=head->next;
        while (newcurr != NULL and curr!=NULL) {
            curr->next=(curr->next==NULL)?NULL:curr->next->next;
            newcurr->next=(newcurr->next==NULL)?NULL:newcurr->next->next;
            curr=curr->next;
            newcurr=newcurr->next;
        }
        return newHead;
    }
};