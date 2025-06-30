class Node {
public:
    int key, value, count;
    Node *prev, *next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        count = 1;
    }
};

class List {
public:
    Node *head, *tail;
    int size = 0;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void removeNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
    unordered_map<int, List*> freqList;
    unordered_map<int, Node*> keyNode;
    int minFreq, currCapacity, maxCapacity;

public:
    LFUCache(int capacity) {
        minFreq = 0;
        currCapacity = 0;
        maxCapacity = capacity;
    }

    void updateFrequency(Node* node) {
        keyNode.erase(node->key);
        freqList[node->count]->removeNode(node);
        if (minFreq == node->count && freqList[node->count]->size == 0) {
            minFreq++;
        }
        List* nextHigherFreq = new List();
        if (freqList.find(node->count + 1) != freqList.end())
            nextHigherFreq = freqList[node->count + 1];
        node->count++;
        nextHigherFreq->addFront(node);
        freqList[node->count] = nextHigherFreq;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFrequency(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxCapacity == 0)
            return;
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFrequency(node);
        } else {
            if (currCapacity == maxCapacity) {
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                currCapacity--;
            }
            currCapacity++;

            // New Value Added therefore its freq = 1;
            minFreq = 1;
            List* currFreq = new List();
            if (freqList.find(minFreq) != freqList.end()) {
                currFreq = freqList[minFreq];
            }
            Node* newNode = new Node(key, value);
            currFreq->addFront(newNode);
            keyNode[key] = newNode;
            freqList[minFreq] = currFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */