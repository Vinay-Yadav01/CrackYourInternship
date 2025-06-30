class MyLinkedList {
    ListNode* head;

public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        ListNode* curr = head;
        while (curr && index--) {
            curr = curr->next;
        }
        return curr ? curr->val : -1;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* curr = head;
        while (curr && index > 1) {
            curr = curr->next;
            index--;
        }

        if (!curr) return; // index is out of bounds

        ListNode* newNode = new ListNode(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (!head) return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* curr = head;
        while (curr->next && index > 1) {
            curr = curr->next;
            index--;
        }

        if (!curr->next) return; // index out of bounds

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */