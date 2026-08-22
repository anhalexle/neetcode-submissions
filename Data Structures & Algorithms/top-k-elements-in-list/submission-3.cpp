class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> myMap;

        for (int num : nums)
        {
            if (myMap[num])
            {
                myMap[num]++;
            }
            else
            {
                myMap[num] = 1;
            }
        }
        vector<pair<int, int>> sortedVec;
        copy(myMap.begin(), myMap.end(), std::back_inserter(sortedVec));

        sort(sortedVec.begin(), sortedVec.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
            return a.second > b.second; // Descending order by value
        });
        
        vector<int> res;
        for (pair<int,int> vec : sortedVec)
        {
            res.push_back(vec.first);
            k--;
            if (k == 0) break;
        }

        return res;
    }
};
