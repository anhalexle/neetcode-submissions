class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subSet;
        int startIndex = 0;
        dfs(startIndex, subSet, res, nums, target);
        return res;
    }
private:
    void dfs(int index, vector<int>& subSet, vector<vector<int>>& res, vector<int>& nums, int target)
    {
        if (target == 0)
        {
            res.push_back(subSet);
            return;
        }
        if (index >= nums.size() || target < 0)
        {
            return;
        }
        subSet.push_back(nums[index]);
        dfs(index, subSet, res, nums, target - nums[index]);
        subSet.pop_back();
        dfs(index + 1, subSet, res, nums, target);
    }
};
