class StockSpanner {
public:
    stack<pair<int,int>> myStack;
    StockSpanner() {
    }
    
    int next(int price) {
        if (myStack.empty())
        {
            myStack.push({price, 1}); // price and span
            return 1;
        }

        int span = 1;
        while(!myStack.empty() && price >= myStack.top().first)
        {
            auto pair = myStack.top();
            myStack.pop();
            span += pair.second;
        }
        myStack.push({price, span});
        return span; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */