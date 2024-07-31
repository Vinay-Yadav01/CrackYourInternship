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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
            int num1 = 0, num2 = 0;
            if(l1) num1 = l1->val; 
            if(l2) num2 = l2->val;
            int sum = num1 + num2 + carry;
            int base = sum%10;
            carry = sum/10;
            ListNode* temp = new ListNode(base);
            tail->next = temp;
            tail = tail->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return ans->next;
    }
};