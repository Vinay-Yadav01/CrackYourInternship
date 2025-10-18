class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        
        if (s.find(head->val) != s.end()) {
            count++;
        }
        
        ListNode* curr = head;
        while (curr->next) {
            if (s.find(curr->next->val) != s.end() && s.find(curr->val) == s.end()) {
                count++;
            }
            curr = curr->next;
        }
        return count;
    }
};