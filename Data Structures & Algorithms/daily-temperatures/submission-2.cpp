class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0);
        stack<pair<int,int>> myStack;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!myStack.empty() && myStack.top().first < temperatures[i])
            {
                pair<int, int> colderDay = myStack.top();
                myStack.pop();
                res[colderDay.second] = i - colderDay.second;
            }
            myStack.push({temperatures[i], i});         
        }
        return res;
    }
};
