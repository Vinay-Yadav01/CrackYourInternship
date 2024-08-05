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
private:
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = reverse(l1);
        ListNode* list2 = reverse(l2);
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        int carry = 0;
        while (list1 != NULL || list2 != NULL || carry) {
            int num1 = 0, num2 = 0;
            if (list1)
                num1 = list1->val;
            if (list2)
                num2 = list2->val;
            int sum = num1 + num2 + carry;
            int base = sum % 10;
            carry = sum / 10;
            ListNode* temp = new ListNode(base);
            tail->next = temp;
            tail = tail->next;
            if (list1)
                list1 = list1->next;
            if (list2)
                list2 = list2->next;
        }
        ans = ans->next;
        return reverse(ans);
    }
};