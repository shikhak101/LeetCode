class FooBar {
private:
    int n;

public:
    mutex c1,c2;
    FooBar(int n) {
        c2.lock();
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            c1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            c2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            c2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            c1.unlock();
        }
    }
};