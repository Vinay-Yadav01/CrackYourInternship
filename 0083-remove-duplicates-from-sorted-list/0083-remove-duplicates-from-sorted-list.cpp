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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr = head;
        ListNode* nextPtr = head->next;
        while(nextPtr!=NULL){
            if(curr->val==nextPtr->val){
                while(nextPtr && curr->val==nextPtr->val){
                    nextPtr=nextPtr->next;
                }
                curr->next=nextPtr;
            }
            curr=curr->next;
            if(nextPtr) nextPtr=nextPtr->next;
        }
        return head;
    }
};