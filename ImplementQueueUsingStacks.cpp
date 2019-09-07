class MyQueue {
public:
    stack<int> s1;
    stack <int> s2;
    int top;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp;
        if(!s2.empty()) {
            temp = s2.top();
            s2.pop();
        }
        else {
            while(!s1.empty()) {
                temp = s1.top();
                s1.pop();
                if(s1.empty()) break;
                s2.push(temp);
            }
        }
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        int temp;
        if(!s2.empty()) {
            temp = s2.top();
        }
        else {
            while(!s1.empty()) {
                temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
        return temp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */