class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // set<int> mySet;
        // for (auto num : nums)
        // {
        //     mySet.insert(num);
        // }
        // vector<int> noDupNums;
        // for (auto it = mySet.begin(); it != mySet.end(); it++)
        // {
        //     noDupNums.push_back(*it);
        // }
        // int l = 0;
        // int r = noDupNums.size() - 1;
        // while (l <= r)
        // {
        //     int m = (l + r) /2;
        //     if (target == noDupNums[m])
        //         return true;
        //     if (noDupNums[l] <= noDupNums[r])
        //     {
        //         if (target < noDupNums[l] || target > noDupNums[m])
        //         {
        //             l = m + 1;
        //         }
        //         else
        //         {
        //             r = m - 1;
        //         }
        //     }
        //     else
        //     {
        //         if (target < noDupNums[m] || target > noDupNums[r])
        //         {
        //             r = m - 1;
        //         }
        //         else
        //         {
        //             l = m + 1;
        //         }
        //     }
        // }
        // return false;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (target == nums[m])
                return true;
            if (nums[l] < nums[m]) { // Left portion
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (nums[l] > nums[m]) { // Right portion
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                l++;
            }
        }
        return false;
    }
};