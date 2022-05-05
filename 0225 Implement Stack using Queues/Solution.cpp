class MyStack {
public:

    queue<int> q1;
    
    int last;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        last = x;
    }
    
    int pop() {
        int toReturn = last;
        queue<int> q2;
        while (q1.size() != 1){
            q2.push(q1.front());
            last = q1.front();
            q1.pop();    
        }
        q1 = q2;
        return toReturn;
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */