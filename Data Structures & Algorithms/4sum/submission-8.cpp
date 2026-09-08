class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((j > i + 1) &&nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    long fourSum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (fourSum > target)
                    {
                        r--;
                    }
                    else if (fourSum < target)
                    {
                        l++;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while (nums[l] == nums[l - 1] && l < r) l++;
                    }
                }
            }
        }
        return res;
    }
};