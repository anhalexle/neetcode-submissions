class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mymap;
        vector<int> myvector;
        for (int i = 0; i < nums.size(); i++)
        {
            int expectVal = target - nums[i];
            if (mymap.find(expectVal) != mymap.end())
            {
                myvector.push_back(mymap[expectVal]);
                myvector.push_back(i);
                return myvector;
            }
            mymap[nums[i]] = i;
        }
    }
};
