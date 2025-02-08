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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        int startcol = 0;
        int startrow = 0;
        int endcol = n - 1;
        int endrow = m - 1;
        bool flagover = false;
        vector<vector<int>> arr(m, vector<int>(n, -1));
        while (head != NULL) {
            for (int i = startcol; i <= endcol; i++) {
                arr[startrow][i] = head->val;
                if (head->next == NULL) {
                    flagover = true;
                    break;
                }
                head = head->next;
            }
            if (flagover) {
                break;
            }
            startrow++;
            for (int i = startrow; i <= endrow; i++) {
                arr[i][endcol] = head->val;
                if (head->next == NULL) {
                    flagover = true;
                    break;
                }
                head = head->next;
            }
            if (flagover) {
                break;
            }
            endcol--;
            for (int i = endcol; i >= startcol; i--) {
                arr[endrow][i] = head->val;
                if (head->next == NULL) {
                    flagover = true;
                    break;
                }
                head = head->next;
            }
            if (flagover) {
                break;
            }
            endrow--;
            for (int i = endrow; i >= startrow; i--) {
                arr[i][startcol] = head->val;
                cout << " " << arr[i][startcol];
                if (head->next == NULL) {
                    flagover = true;
                    break;
                }
                head = head->next;
            }
            if (flagover) {
                break;
            }
            startcol++;
        }

        return arr;
    }
};