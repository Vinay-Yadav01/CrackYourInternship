class Node {
public:
    int key;
    int value;
    Node *prev, *next;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    unordered_map<int, Node*> mp;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    void insertNode(Node* node) {
        Node* front = head->next;
        head->next = node;
        node->next = front;
        front->prev = node;
        node->prev = head;
    }
    void deleteNode(Node* node) {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* resnode = mp[key];
            int res = resnode->value;
            mp.erase(key);
            deleteNode(resnode);
            insertNode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* exist = mp[key];
            mp.erase(key);
            deleteNode(exist);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */