class DLL {
public:
    string val;
    DLL *next, *prev;
    DLL() {
        val = "";
        next = prev = NULL;
    }
    DLL(string x) {
        val = x;
        next = prev = NULL;
    }
};

class BrowserHistory {
    DLL *head, *curr;

public:
    BrowserHistory(string homepage) {
        head = new DLL(homepage);
        curr = head;
    }

    void visit(string url) {
        DLL* newNode = new DLL(url);
        newNode->prev = curr;
        curr->next = newNode;
        curr = newNode;
    }

    string back(int steps) {
        while (steps-- && curr != head) {
            curr = curr->prev;
        }
        return curr->val;
    }

    string forward(int steps) {
        while (steps-- && curr->next != NULL) {
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */