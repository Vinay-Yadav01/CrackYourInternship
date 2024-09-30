class CustomStack {
public:
    vector<int> stack;
    vector<int> inc;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        inc.resize(maxSize, 0); // Auxiliary array to store the inc values.
    }
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int idx = stack.size() - 1;
        int val = stack.back() + inc[idx];
        stack.pop_back();
        if (idx > 0) {
            inc[idx - 1] += inc[idx];
        }
        inc[idx] = 0; // Reset the inc value since it's already applied.
        return val;
    }

    void increment(int k, int val) {
        int count = min(k, (int)stack.size());
        if (count > 0) {
            inc[count - 1] += val; // Accumulate inc at the appropriate level.
        }
    }
};
