class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort
        if (nums.size() == 0) return 0;
        int max = 0, tempMax = 1;

        sort(nums.begin(), nums.end());
        vector<int> noDupVec;
        unordered_set<int> mySet;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mySet.find(nums[i]) == mySet.end())
            {
                noDupVec.push_back(nums[i]);
                mySet.insert(nums[i]);
            }
        }
        for (int i = 1; i < noDupVec.size(); i++)
        {
            if (noDupVec[i] == (noDupVec[i - 1] + 1)) ++tempMax;
            else
            {
                max = std::max(max, tempMax);
                tempMax = 1;
            }
        }
        return std::max(max,tempMax);
    }
};
