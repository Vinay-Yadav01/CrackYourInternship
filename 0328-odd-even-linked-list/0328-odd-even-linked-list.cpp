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
        int k = 1;
        ListNode* temp = head;
        ListNode* oddHead = new ListNode(-1);
        ListNode *oddTail = oddHead;
        ListNode* evenHead = new ListNode(-1);
        ListNode *evenTail = evenHead;
        while (temp != NULL) {
            ListNode* newNode = new ListNode(temp->val);
            if (k % 2 == 0) {
                evenTail->next = newNode;
                evenTail = evenTail->next;
            } else {
                oddTail->next = newNode;
                oddTail = oddTail->next;
            }
            k++;
            temp = temp->next;
        }
        evenTail->next = NULL;
        oddTail->next = evenHead->next;
        return oddHead->next;
    }
};