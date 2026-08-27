using OpFunc = std::function<int(int, int)>;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}
class Solution {   
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        map<string,OpFunc> myMap = {
            {"+", add},
            {"-", sub},
            {"*", mul},
            {"/", divide}
        };
        for (auto token :tokens)
        {
            if (myMap.contains(token))
            {
                if (myStack.size() >= 2)
                {
                    int val1 = myStack.top();
                    myStack.pop();
                    int val2 = myStack.top();
                    myStack.pop();
                    myStack.push(myMap[token](val2, val1));
                }
                else
                    return -1;
            }
            else
            {
                myStack.push(stoi(token));
            }
        }
        return myStack.top();
    }
};
