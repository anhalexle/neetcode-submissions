class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // just calculate area when heights[i] < stack.top().first (height) to reduce + 1
        if (heights.size() == 1) return heights[0];
        stack<pair<int,int>> myStack; // {height, index}
        int maxSize = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int tempIndex = i;
            while (!myStack.empty() && myStack.top().first >= heights[i])
            {
                auto [height, index] = myStack.top();
                tempIndex = index;
                myStack.pop();
                maxSize = max(maxSize, (i - index)*height); // no + 1 here, index 3: 7, index 4: 2 -> maxSize[3] = 7 * (4 -3) = 7
            }
            myStack.push({heights[i], tempIndex});
        }

        int maxIndex = heights.size() - 1;
        while(!myStack.empty())
        {
            auto [height, index] = myStack.top();
            myStack.pop();
            maxSize = max(maxSize, (maxIndex - index + 1)*height);
        }
        return maxSize;
    }
};
