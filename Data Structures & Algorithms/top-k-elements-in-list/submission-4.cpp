class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> maxHeap;
        unordered_map<int, int> myMap;
        for (auto num :nums)
        {
            myMap[num]++;
        }
        for (auto it : myMap)
        {
            maxHeap.push({it.second, it.first});
        }

        for (int i = 0; i < k; i++)
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
