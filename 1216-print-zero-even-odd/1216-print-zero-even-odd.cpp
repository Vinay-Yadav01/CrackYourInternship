class ZeroEvenOdd {
private:
    int n;
    mutex zeroLock, evenLock, oddLock;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        evenLock.lock();
        oddLock.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            zeroLock.lock();
            printNumber(0);
            if (i % 2)
                oddLock.unlock();
            else
                evenLock.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            evenLock.lock();
            printNumber(i);
            zeroLock.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            oddLock.lock();
            printNumber(i);
            zeroLock.unlock();
        }
    }
};