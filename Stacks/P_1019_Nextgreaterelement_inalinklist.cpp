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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodes;
        ListNode* temp = head;
        stack<int> st;
        st.push(-1);
        while (temp) {
            nodes.push_back(temp->val);
            temp = temp->next;
        }

        int n = nodes.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 and st.top() <= nodes[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(nodes[i]);
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1)
                ans[i] = 0;
        }
        return ans;
    }
};