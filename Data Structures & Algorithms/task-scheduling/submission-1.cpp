class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        queue<pair<int,int>> taskQueues; // {amountOfTask, timeToExecute}
        unordered_map<int, int> myMap; // {task: counterOfTasks}
        // O(n)
        for (auto task : tasks)
        {
            myMap[task]++;
        }

        // O(26log26)
        for (auto it : myMap)
        {
            maxHeap.push(it.second);
        }
        int cycleNeeded = 0;
        while (!maxHeap.empty() || !taskQueues.empty())
        {
            if (!maxHeap.empty())
            {
                auto countTaskLeft = maxHeap.top();
                maxHeap.pop();
                cycleNeeded++;
                --countTaskLeft;
                if (countTaskLeft != 0)
                {
                    taskQueues.push({countTaskLeft, cycleNeeded + n});
                }
            }
            if (!taskQueues.empty() && taskQueues.front().second == cycleNeeded)
            {
                auto [taskCounterLeft, timeWait] = taskQueues.front();
                taskQueues.pop();              
                maxHeap.push({taskCounterLeft});
            }
            if (maxHeap.empty() && !taskQueues.empty()) // no task left now add idle
            {
                cycleNeeded = taskQueues.front().second;
            }
        }
        return cycleNeeded;
    }
};
