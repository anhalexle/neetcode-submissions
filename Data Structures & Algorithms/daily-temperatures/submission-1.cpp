class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0);
        stack<pair<int,int>> myStack;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while(!myStack.empty() && temperatures[i] > myStack.top().first)
            {
                auto pair = myStack.top();
                myStack.pop();
                res[pair.second] = i - pair.second;
            }
            myStack.push({temperatures[i], i});
        }
        return res;
    }
};
