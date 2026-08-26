class MinStack {
public:
    stack<int> myStack, myMin;
    MinStack() {
        
    }
    
    void push(int val) {
        myStack.push(val);
        if (myMin.empty() || (val <= myMin.top()))
            myMin.push(val);
        else
            myMin.push(myMin.top());
    }
    
    void pop() {
        myStack.pop();
        myMin.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return myMin.top();
    }
};
