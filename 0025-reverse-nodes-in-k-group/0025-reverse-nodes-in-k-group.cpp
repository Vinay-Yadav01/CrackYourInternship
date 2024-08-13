class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are at least k nodes left in the list
        ListNode* node = head;
        int count = 0;
        while (count < k && node != NULL) {
            node = node->next;
            count++;
        }

        // If we have less than k nodes, return the head as is
        if (count < k) {
            return head;
        }

        // Step 1: Reverse the first k nodes
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 2: Recursively reverse the next part of the list
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        // Step 3: Return the new head of the reversed list
        return prev;
    }
};
