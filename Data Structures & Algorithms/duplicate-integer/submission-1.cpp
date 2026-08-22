class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mymap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mymap.find(nums[i]) == mymap.end())
                mymap.insert({nums[i], 1});
            else
                mymap[nums[i]] += 1;
        }
        map<int,int>::iterator itr;
        for (itr = mymap.begin(); itr != mymap.end(); ++ itr)
        {
            if (itr-> second != 1)
                return true;
        }
        return false;
    }
};
