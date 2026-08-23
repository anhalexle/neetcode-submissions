class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> myMap;
        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }
        for (auto it = myMap.begin(); it != myMap.end(); it++)
        {
            if (it->second > nums.size() /2)
                return it->first;
        }
        return 0;
    }
};