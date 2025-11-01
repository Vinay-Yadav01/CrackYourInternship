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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        if (!head || !head->next || !head->next->next)
            return ans; 
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1; 
        int first = -1, last = -1;
        int minDist = INT_MAX;

        while (curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                if (first == -1)
                    first = index; 
                else
                    minDist = min(minDist, index - last);

                last = index; 
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (first == last)
            return ans; 
        ans[0] = minDist;
        ans[1] = last - first;
        return ans;
    }
};
