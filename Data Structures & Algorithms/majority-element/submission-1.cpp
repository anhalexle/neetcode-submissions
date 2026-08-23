class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int> myMap;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     myMap[nums[i]]++;
        // }
        // for (auto it = myMap.begin(); it != myMap.end(); it++)
        // {
        //     if (it->second > nums.size() /2)
        //         return it->first;
        // }
        // return 0;
        int count = 1, res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (count == 0)
            {
                res = nums[i];
                count = 1;
                continue;
            }
            if (res == nums[i])
                count++;
            else
            {
                count--;
            }
        }
        return res;
    }
};