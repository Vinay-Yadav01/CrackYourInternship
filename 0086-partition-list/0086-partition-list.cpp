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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* smaller = new ListNode(-1);
        ListNode* stail = smaller;
        ListNode* larger = new ListNode(-1);
        ListNode* ltail = larger;
        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) {
                stail->next = temp;
                stail = stail->next;
            } else {
                ltail->next = temp;
                ltail = ltail->next;
            }
            temp = temp->next;
        }
        ltail->next = NULL;
        stail->next = larger->next;
        return smaller->next;
    }
};