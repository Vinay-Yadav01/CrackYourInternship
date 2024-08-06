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
            curr=curr->next;
            ans++;
        }
        return ans;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = length(head);
        int start = k, last = size-k+1;
        ListNode* first=NULL, *second=NULL, *curr=head;
        while(curr!=NULL){
            start--;
            if(start==0) first=curr;
            last--;
            if(last==0) second = curr;
            curr=curr->next;
        }
        swap(first->val, second->val);
        return head;
    }
};