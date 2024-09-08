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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        ListNode* curr = head;
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        int bucketSize = count / k;
        int remainingNode = count % k;
        curr = head;
        for (int i = 0; i < k; i++) {
            ans[i] = curr;
            ListNode* prev = NULL;
            for (int j = 0; j < bucketSize + (remainingNode > 0 ? 1 : 0); j++) {
                prev = curr;
                curr = curr->next;
            }
            if (prev)
                prev->next = NULL;
            remainingNode--;
        }
        return ans;
    }
};