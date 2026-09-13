class FreqStack {
public:
    stack<int> myStack;
    map<int, int> myMap;
    int max = 0;
    FreqStack() {
    
    }
    
    void push(int val) {
        myMap[val]++;
        myStack.push(val);
        updateMax();
    }

    void updateMax()
    {
        int tempMax = 0;
        for (auto &it : myMap)
        {
            if (it.second > tempMax)
            {
                tempMax = it.second;
            }
        }
        max = tempMax;
    }
    
    int pop() {
        int topVal = myStack.top();
        if (myMap[topVal] == max)
        {
            myStack.pop();
            myMap[topVal]--;
        }
        else
        {
            vector<int> myVector;
            while (!myStack.empty())
            {
                myVector.push_back(topVal);
                myStack.pop();
                topVal = myStack.top();
                if (myMap[topVal] == max)
                {
                    myStack.pop();
                    myMap[topVal]--;
                    break;
                }
            }
            if (!myVector.empty())
            {
                for (int i = myVector.size() - 1; i>= 0; i--)
                {
                    myStack.push(myVector[i]);
                }
            }
        }
        updateMax();
        return topVal;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */