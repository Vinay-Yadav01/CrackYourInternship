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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        int sum = 0;
        ListNode* dummy = new ListNode(0,NULL);
        ListNode *prev = dummy;
        while(curr){
            if(curr->val==0){
                ListNode* newNode = new ListNode(sum);
                prev->next = newNode;
                prev = prev->next;
                sum = 0;
            }
            sum+=curr->val;
            curr = curr->next;
        }
        return dummy->next;
    }
};