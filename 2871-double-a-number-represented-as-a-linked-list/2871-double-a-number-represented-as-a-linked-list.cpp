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
    ListNode* doubleIt(ListNode* head) {
        if (!head) return nullptr;

        // Step 1: Reverse the list
        ListNode* rev = reverse(head);
        ListNode* curr = rev;
        int carry = 0;
        ListNode* prev = nullptr;

        // Step 2: Double each digit
        while (curr) {
            int sum = curr->val * 2 + carry;
            curr->val = sum % 10;
            carry = sum / 10;
            prev = curr;
            curr = curr->next;
        }

        // Step 3: Handle leftover carry
        if (carry) {
            prev->next = new ListNode(carry);
        }

        // Step 4: Reverse back to original order
        return reverse(rev);
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

