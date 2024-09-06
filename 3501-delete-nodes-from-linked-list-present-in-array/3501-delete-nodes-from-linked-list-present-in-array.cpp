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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num] = 1;
        }
        ListNode *prev = NULL, *curr = head;
        while (curr != NULL) {
            int elem = curr->val;
            if (mp.find(elem) != mp.end()) { // It exist
                ListNode* temp = curr;
                if (prev == NULL) {
                    curr = curr->next;
                    head = head->next;
                } else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};