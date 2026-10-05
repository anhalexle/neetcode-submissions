class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1) return heights[0];
        stack<pair<int,int>> myStack; // {height, index}
        int maxSize = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (myStack.empty())
            {
                myStack.push({heights[i], i});
                
            }
            else
            {
                int tempIndex = i;
                while (!myStack.empty() && myStack.top().first >= heights[i])
                {
                    auto value = myStack.top();
                    tempIndex = value.second;
                    myStack.pop();
                    if (!myStack.empty())
                    {
                        maxSize = max(maxSize, (value.second - myStack.top().second + 1) * myStack.top().first);
                    }
                }
                myStack.push({heights[i], tempIndex});
            }
            maxSize = max(maxSize, (i - myStack.top().second + 1) * myStack.top().first);
        }
        int maxIndex = heights.size() - 1;
        while (!myStack.empty())
        {
            auto topVal = myStack.top();
            myStack.pop();
            maxSize = max(maxSize, (maxIndex - topVal.second + 1) * topVal.first);
        }
        return maxSize;
    }
};
