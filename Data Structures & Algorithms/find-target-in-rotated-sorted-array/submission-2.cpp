class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
                // Left portion
            if (nums[l] <= nums[m]) // L == R
            {
                if (nums[l] > target or nums[m] < target) // set out about target not in (nums[l], nums[m])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            else
            {
                if (nums[m] > target or nums[r] < target)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
