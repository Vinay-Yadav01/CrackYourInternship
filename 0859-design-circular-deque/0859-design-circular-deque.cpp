class MyCircularDeque {
public:
    int size;
    int front, rear;
    vector<int> temp;
    
    MyCircularDeque(int k) {
        size = k;
        front = -1;
        rear = -1;
        temp.resize(k);
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;  // Wrap around to the end
        } else {
            front--;
        }
        temp[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;  // Wrap around to the start
        } else {
            rear++;
        }
        temp[rear] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        if (front == rear) {  // Only one element
            front = rear = -1;  // Reset deque to empty state
        } else if (front == size - 1) {
            front = 0;  // Wrap around to the start
        } else {
            front++;
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        if (front == rear) {  // Only one element
            front = rear = -1;  // Reset deque to empty state
        } else if (rear == 0) {
            rear = size - 1;  // Wrap around to the end
        } else {
            rear--;
        }
        return true;
    }

    int getFront() {
        return (isEmpty()) ? -1 : temp[front];
    }

    int getRear() {
        return (isEmpty()) ? -1 : temp[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }
};
