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
    int findGCD(int num1, int num2) {
        if (num1 == 0)
            return num2;
        if (num2 == 0)
            return num1;
        while (num1 != num2) {
            if (num1 < num2)
                num2 -= num1;
            else
                num1 -= num2;
        }
        return num1;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *prev = head, *curr = head->next;
        while (curr) {
            int num1 = prev->val;
            int num2 = curr->val;
            int gcd = findGCD(num1, num2);
            ListNode* newNode = new ListNode(gcd);
            prev->next = newNode;
            newNode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};