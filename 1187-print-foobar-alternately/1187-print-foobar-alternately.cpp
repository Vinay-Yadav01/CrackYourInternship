class FooBar {
private:
    int n;
    mutex fooLock; // added
    mutex barLock; // added

public:
    FooBar(int n) {
        this->n = n;
        barLock.lock(); // added
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            fooLock.lock(); // added

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            barLock.unlock(); // added
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            barLock.lock(); // added
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            fooLock.unlock(); // added
        }
    }
};