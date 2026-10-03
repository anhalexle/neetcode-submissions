class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time;
        // Max heap
        priority_queue<int> maxHeap; // to store the task that needs to be done most
        queue<pair<int, int>> myQueue; // {counterOfExecuteChanceLeft of that task, timeToExecute}
        // create a hashmap to store the counter of each task
        unordered_map<char, int> myMap;
        for (auto task : tasks)
        {
            myMap[task]++;
        }

        // push the counter of the task to the maxHeap to get the most repeated tasks
        for (auto it : myMap)
        {
            maxHeap.push(it.second); //push counter only
        }

        while (!maxHeap.empty() || !myQueue.empty())
        {
            time++;
            if (!maxHeap.empty()) // ONLY executor
            {
                auto largestCounterTask = maxHeap.top();
                maxHeap.pop();
                --largestCounterTask;
                if (largestCounterTask != 0)
                {
                    int waitTime = time + n;
                    myQueue.push({largestCounterTask, waitTime});
                }
            }
            if (!myQueue.empty() && time == myQueue.front().second)
            {
                auto topEl = myQueue.front();
                myQueue.pop();
                maxHeap.push(topEl.first);
            }
            
        }
        return time;
    }
};
