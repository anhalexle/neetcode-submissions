class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] >= target)
        //         return i;
        // }
        // if (target > nums[nums.size() - 1])
        //     return nums.size();
        // return -1;
        int l = 0, r = nums.size() - 1;
        int m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (target > nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};