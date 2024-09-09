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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int sRow = 0, sCol = 0, eRow = m-1, eCol = n-1;
        ListNode* curr = head;
        while(curr!=NULL){
            for(int i=sCol;i<=eCol && curr;i++){
                if(!curr) return ans;
                ans[sRow][i] = curr->val;
                curr=curr->next;
            }
            sRow++;
            for(int i=sRow;i<=eRow && curr;i++){
                if(!curr) return ans;
                ans[i][eCol] = curr->val;
                curr=curr->next;
            }
            eCol--;
            for(int i=eCol;i>=sCol && curr;i--){
                if(!curr) return ans;
                ans[eRow][i] = curr->val;
                curr=curr->next;
            }
            eRow--;
            for(int i=eRow;i>=sRow && curr;i--){
                if(!curr) return ans;
                ans[i][sCol] = curr->val;
                curr=curr->next;
            }
            sCol++;
        }
        return ans;
    }
};