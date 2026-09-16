class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        if (heights.size() == 1) return heights[0];
        stack<pair<int, int>> myStack;
        myStack.push(make_pair(0, heights[0]));
        int max = 0;
        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[i] >= myStack.top().second)
            {
                myStack.push({i, heights[i]});
            }
            else
            {
                int location = i;
                while (!myStack.empty() && heights[i] < myStack.top().second)
                {
                    location = myStack.top().first;
                    max = std::max(max, (i - location) * myStack.top().second);
                    myStack.pop();
                }
                myStack.push({location, heights[i]});
            }
        }
        int lastIndex = heights.size() - 1;
        while (!myStack.empty())
        {
            int topIndex = myStack.top().first;
            max = std::max(max, (lastIndex - topIndex + 1) * myStack.top().second);
            myStack.pop();
        }
        return max;
    }
};
