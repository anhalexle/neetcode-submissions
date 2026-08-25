class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int curLength = q1.size();
        int res = 0;
        for (int i = 0; i < curLength; i++)
        {
            if (i == curLength - 1)
            {
                res = q1.front();   
            }
            else
            {
                q2.push(q1.front());
            }
            q1.pop();
        }
        for (int i = 0; i < curLength - 1; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }
    
    int top() {
        return q1.back();
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