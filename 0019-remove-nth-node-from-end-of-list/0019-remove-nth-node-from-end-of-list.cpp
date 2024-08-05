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
    int length(ListNode* head){
        ListNode* curr=head;
        int ans=0;
        while(curr!=NULL){
            ans++;
            curr=curr->next;
        }
        return ans;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = length(head);
        int nodeToDelete = size-n;
        if(nodeToDelete==0) return head->next;
        ListNode *prev=NULL, *curr=head;
        for(int i=0;i<nodeToDelete;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
    }
};