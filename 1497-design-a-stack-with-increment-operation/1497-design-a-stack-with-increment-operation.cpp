class CustomStack {
public:
    vector<int> st;
    int maxSize;

    CustomStack(int maxSize) { this->maxSize = maxSize; }

    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
        }
    }

    int pop() {
        if (st.empty()) {
            return -1;
        } else {
            int val = st.back();
            st.pop_back();
            return val;
        }
    }

    void increment(int k, int val) {
        int count = min(k, (int)st.size());
        for (int i = 0; i < count; i++) {
            st[i] += val;
        }
    }
};
