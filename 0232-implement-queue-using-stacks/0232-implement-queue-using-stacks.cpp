class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    MyQueue() {}

    void push(int x) {
        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        int popped = st.top();
        st.pop();
        return popped;
    }

    int peek() {
        if (!st.empty())
            return st.top();
        else
            return -1;
    }

    bool empty() { return st.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */