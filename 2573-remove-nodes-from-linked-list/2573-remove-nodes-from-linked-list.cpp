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
    void solve(ListNode* head, vector<int>& ans, stack<int>& nextGreater) {
        if (!head) {
            nextGreater.push(0);
            return;
        }
        solve(head->next, ans, nextGreater);
        while (!nextGreater.empty() && nextGreater.top() <= head->val) {
            nextGreater.pop();
        }
        if (!nextGreater.empty())
            ans.push_back(nextGreater.top());
        else
            ans.push_back(0);

        nextGreater.push(head->val);
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> nextGreater;
        solve(head, ans, nextGreater);
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> nextLarger = nextLargerNodes(head);
        ListNode* dummy = new ListNode(-1);
        int i = 0;
        ListNode* curr = head, *prev = dummy;
        while(curr){
            if(!nextLarger[i]){
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
            i++;
        }
        return dummy->next;
    }
};