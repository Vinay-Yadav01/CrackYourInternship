/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    public:
    Node* copyRandomList(Node* head) {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        //step3: random pointer copy
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random?temp->random->next:temp->random;
            }
            temp=temp->next->next;
        }
        
        //step 4: revert step 2 changes
        originalNode = head;
        cloneNode = cloneHead;
        
         while (originalNode!=NULL && cloneNode!=NULL)
            {
                originalNode->next = cloneNode->next;
                originalNode=originalNode->next; 
                
                if(originalNode!=NULL) cloneNode->next=originalNode->next;
                cloneNode = cloneNode->next;
            }

        // step 5 answer return
        return cloneHead;
    }
};