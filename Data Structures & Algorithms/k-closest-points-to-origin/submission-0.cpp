class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for (int i = 0; i < points.size(); i++)
        {
            int distance = (int)pow(points[i][0],2) + (int)pow(points[i][1],2);
            minHeap.push({distance, i});
        }

        for (int i = 0; i < k; i++)
        {
            res.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }
        return res;
    }
};
