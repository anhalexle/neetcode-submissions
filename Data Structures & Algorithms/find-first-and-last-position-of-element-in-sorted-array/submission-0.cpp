class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerBound(nums, target);
        if (l == nums.size() || nums[l] != target)
        {
            return {-1, -1};
        }
        int r = lowerBound(nums, target + 1) /*get start index of target + 1*/ - 1; // get the last index
        return {l, r};
    }
private:
    int lowerBound(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size(); // r to found in case no target + 1
        while (l < r) // left boundary ,"<=" is" no exit
        {
            int m = l + (r - l)/2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};