class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mymap;
        vector<vector<int>> bucket(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++){
            mymap[nums[i]]++;
        }
        for (map<int,int>::iterator itr = mymap.begin(); itr != mymap.end(); itr++)
        {
            bucket[itr->second].push_back(itr->first);
        }
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < bucket[i].size(); j++)
            {
                res.push_back(bucket[i][j]);
                if (res.size() == k)
                {
                    return res;
                }
            }
        }
        

    }
};
