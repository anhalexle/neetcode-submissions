class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> mySet(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++)
        {
            if (mySet.find(i) == mySet.end()) return i;
        }
        return -1;
    }
};
