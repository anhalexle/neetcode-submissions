class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> myMap;
        for (auto num: nums)
        {
            if (!myMap[num])
            {
                myMap[num] = 1;
            }
            else
                ++myMap[num];
        }
        int n = nums.size();
        vector<int> res;
        for (auto it = myMap.begin(); it != myMap.end(); it++)
        {
            if (it->second > n / 3)
                res.push_back(it->first);
        }
        return res;
    }
};