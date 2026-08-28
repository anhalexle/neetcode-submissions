class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> mySet;
        for (auto num:nums)
        {
            mySet.insert(num);
        }
        for (int i = 1; i <= nums.size() + 1; i++)
        {
            if (!mySet.contains(i))
                return i;
        }
        return -1;
    }
};