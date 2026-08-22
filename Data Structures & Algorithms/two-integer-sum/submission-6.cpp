class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (myMap.count(diff) && myMap[diff] != i)
                return {i, myMap[diff]};
        }
        return {};
    }
};
